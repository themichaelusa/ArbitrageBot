class Position(object):

	def __init__(self, quantity=None, shortPrice=None, longPrice=None):
		self.quantity = quantity
		self.shortPrice = shortPrice
		self.longPrice = longPrice
		self.isComplete = False
		self.completionTime = None

	def setCompleteParams(self):
		import time
		self.completionTime = time.time()
		self.isComplete = True

	def toDict(self):
		return self.__dict__

		