from AssignmentManager import Exam

QUESTIONS = ["What animal is a border collie?", "What color is the sky", "What is 1 + 1", "Who is the tiger king", "Who is mario's brother?", "Who is luigi's brother"]
ANSWERS = ["dog", "blue", "2", "joe", "luigi", "mario"]

exam = Exam(QUESTIONS, ANSWERS)
exam.simulate()