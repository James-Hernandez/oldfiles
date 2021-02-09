from mesa import Agent, Model
from mesa.time import RandomActivation
from mesa.space import MultiGrid
from mesa.datacollection import DataCollector
from mesa.batchrunner import BatchRunner


def compute_gini(model):
    agent_sickness = [agent.sick for agent in model.schedule.agents]
    x = sorted(agent_sickness)
    N = model.num_agents
    B = sum(xi * (N-i) for i, xi in enumerate(x)) / (N*sum(x))
    return (1 + (1/N) - 2*B)


class CoronaAgent(Agent):
    """ An agent with fixed initial sick."""

    def __init__(self, unique_id, model):
        super().__init__(unique_id, model)
        self.sick = 1

    def move(self):
        possible_steps = self.model.grid.get_neighborhood(
            self.pos,
            moore=True,
            include_center=False)
        new_position = self.random.choice(possible_steps)
        self.model.grid.move_agent(self, new_position)

    def give_sickness(self):
        cellmates = self.model.grid.get_cell_list_contents([self.pos])
        if len(cellmates) > 1:
            other = self.random.choice(cellmates)
            other.sick += 1
            #self.sick -= 1

    def step(self):
        self.move()
        if self.sick > 0:
            self.give_sickness()

class HealthyAgent(Agent):
    """ An agent with fixed initially not sick."""

    def __init__(self, unique_id, model):
        super().__init__(unique_id, model)
        self.sick = 0

    def move(self):
        possible_steps = self.model.grid.get_neighborhood(
            self.pos,
            moore=True,
            include_center=False)
        new_position = self.random.choice(possible_steps)
        self.model.grid.move_agent(self, new_position)

    # def give_sickness(self):
    #     cellmates = self.model.grid.get_cell_list_contents([self.pos])
    #     if len(cellmates) > 1:
    #         other = self.random.choice(cellmates)
    #         other.sick += 1
    #         #self.sick -= 1

    def step(self):
        self.move()
        # if self.sick > 0:
        #     self.give_sickness()


class CoronaModel(Model):
    """A model with some number of agents."""

    def __init__(self, N, width, height):
        self.num_agents = N
        self.grid = MultiGrid(width, height, True)
        self.schedule = RandomActivation(self)
        self.running = True

        # Create agents
        for i in range(self.num_agents - 1):
            a = HealthyAgent(i, self)
            self.schedule.add(a)
            # Add the agent to a random grid cell
            x = self.random.randrange(self.grid.width)
            y = self.random.randrange(self.grid.height)
            self.grid.place_agent(a, (x, y))

        for i in range(1):
            a = CoronaAgent(i,self)
            self.schedule.add(a)
            # Add the agent to a random grid cell
            x = self.random.randrange(self.grid.width)
            y = self.random.randrange(self.grid.height)
            self.grid.place_agent(a, (x, y))

        self.datacollector = DataCollector(
            model_reporters={"Gini": compute_gini},
            agent_reporters={"Sick": "sick"}
        )

    def step(self):
        self.datacollector.collect(self)
        self.schedule.step()


fixed_params = {
    "width": 10,
    "height": 10
}


variable_params = {"N": range(10, 500, 10)}

# The variables parameters will be invoke along with the fixed parameters allowing for either or both to be honored.
batch_run = BatchRunner(
    CoronaModel,
    variable_params,
    fixed_params,
    iterations=5,
    max_steps=100,
    model_reporters={"Gini": compute_gini}
)

batch_run.run_all()
