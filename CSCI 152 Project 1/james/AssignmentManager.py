class SingleQuestion:
  def __init__(self, question, answer):
    if type(question) is not str:
      raise ValueError("SingleQuestion: Question must be string")
    if type(answer) is not str:
      raise ValueError("SingleQuestion: Answer must be string")
    self.question = question
    self.answer = answer
  
  def simulate(self):
    answer = input(self.question + "\nAnswer: ")
    self.check(answer)

  def check(self, answer):
    if self.answer == answer: 
      print("Correct") 
    else: 
      print("Wrong")

class Homework:
  def __init__(self, description):
    if type(description) is not str:
      raise ValueError("Homework: Description must be string")
    self.description = description
  
  def simulate(self):
    print("Homework description: " + self.description)
  
class Exam:
  def __init__(self, nQuestions, nAnswers):
    if type(nQuestions) is not list: 
      raise ValueError('Exam: Questions require list type')
    if type(nAnswers) is not list: 
      raise ValueError('Exam: Answers require list type')
    if len(nQuestions) != len(nAnswers):
      raise ValueError('Exam: Number of questions must match number of answers')
     
    self.nQuestions = nQuestions
    self.nAnswers = nAnswers

  def simulate(self):
    for i, question in enumerate(self.nQuestions):
      answer = input(question + ": ")
      self.check(i, answer)

  def check(self, index, answer):
    if self.nAnswers[index] == answer:
      print("Correct")
    else:
      print("Wrong")  
  

class Quiz:
  def __init__(self, nQuestions, nAnswers):
    if type(nQuestions) is not list:
      raise ValueError('Quiz: Questions require list type')
    if len(nQuestions) != 5:
      raise ValueError('Quiz: Require 5 questions')
    if type(nAnswers) is not list:
      raise ValueError('Quiz: Answers require list type')
    if len(nAnswers) != 5:
      raise ValueError('Quiz: Require 5 answers')

    self.nQuestions = nQuestions
    self.nAnswers = nAnswers

  def simulate(self):
    for i, question in enumerate(self.nQuestions):
      answer = input(question + ": ")
      self.check(i, answer)

  def check(self, index, answer):
    if self.nAnswers[index] == answer:
      print("Correct")
    else:
      print("Wrong")      

class Essay: 
  def __init__(self, description, wordCountLimit):
    if type(description) is not str:
      raise ValueError("Essay: Description must be string")
    if type(wordCountLimit) is not int:
      raise ValueError("Essay: Word count must be an int")
    self.description = description
    self.wordCountLimit = wordCountLimit
  
  def simulate(self):
    print(self.description)
    print("Maximum word count " + str(self.wordCountLimit))
    essay = input("Write your essay: ")
    if self.isOverWordCount(essay):
      print("ERROR: Essay is over word count")
    else:
      print("Essay successfully submitted")
    
  def isOverWordCount(self, essay):
    return len(essay.split(' ')) > self.wordCountLimit



