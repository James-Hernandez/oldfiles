from CoronaModel import *
from mesa.visualization.modules import CanvasGrid
from mesa.visualization.ModularVisualization import ModularServer
from mesa.visualization.modules import ChartModule

def agent_portrayal(agent):
    portrayal = {"Shape": "circle",
                 "Filled": "true",
                 "r": 0.6}

    if agent.sick >= 5:
        portrayal["Color"] = "black"
        portrayal["Layer"] = -1
        portrayal["r"] = 0.5
        
    elif agent.sick >= 1:
        portrayal["Color"] = "red"
        portrayal["Layer"] = 0
    
    else:
        portrayal["Color"] = "green"
        portrayal["Layer"] = 1
        portrayal["r"] = 0.4
    return portrayal

grid = CanvasGrid(agent_portrayal, 10, 10, 500, 500)
chart = ChartModule([{"Label": "Gini",
                      "Color": "Black"}],
                    data_collector_name='datacollector')

server = ModularServer(CoronaModel,
                       [grid, chart],
                       "Corona Model",
                       {"N":100, "width":10, "height":10})
server.port = 8521 # The default
server.launch()