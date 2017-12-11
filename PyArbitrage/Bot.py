
class Bot(object):

	def __init__(self, quantity, e1Keys, e2Keys):
		from GDAX_API import GDAX
		from CEX_API import CEX
		self.gdaxWrapper = GDAX(quantity, *e1Keys)
		self.cexWrapper = CEX(quantity, *e2Keys)
		self.generateTextFile()
		self.quantity = quantity

	#### USER-END FUNCTIONS ####
	def start(self, endTime=None, numTrades=None):

		if (endTime != None):
			import time
			while(time.time() < endTime):
				potentialArb = self.tryArbitrage()
				if (potentialArb[1]):
					self.writeToTextFile(potentialArb[0])

		if (numTrades != None):
			totalTrades = 0 
			while (totalTrades < numTrades):
				potentialArb = self.tryArbitrage()
				if (potentialArb[1]):
					self.writeToTextFile(potentialArb[0])
					totalTrades += 1

	#### ARBITRAGE FUNCTIONS ####
	def tryArbitrage(self):
		longSpot = self.bfxWrapper.getSpotPrice()
		shortSpot = self.cexWrapper.getSpotPrice()

		if (self.isProfitableSpread(longSpot, shortSpot)):
			return (executeArbitrage(longSpot, shortSpot), True)
		else:
			import Position as pos
			return (pos.Position(), False)

	def isProfitableSpread(self, longSpot, shortSpot):
		#TODO: Include additional parameters beyond just ROI
		lCommission = self.bfxWrapper.getCommission()
		sCommission = self.cexWrapper.getCommission()
		spread = shortSpot-longSpot;
		adjSpread = spread-(spread*(lCommission+sCommission))

		if (adjSpread > 0):
			return true
		else:
			return false

	def executeArbitrage(self, longSpot, shortSpot):
		#TODO: IMPLEMENT ARBITRAGE
		self.bfxWrapper.goLong()
		self.cexWrapper.goShort()

		#TODO: VERIFY FUNDS ARE SETTLED
		import Position as pos
		tradeData = pos.Position(self.quantity, longSpot, shortSpot)
		tradeData.setCompleteParams()
		return tradeData

	##### LOGGING FUNCTIONS #####
	def generateTextFile(self):
		import Position as pos
		headers = list(pos.Position().toDict().keys())
		commaDelim = ",".join(headers)

		f = open('trades.txt', 'w+')
		f.write(commaDelim + "\n")
		f.close()

	def writeToTextFile(self, pos): 

		if (pos.isComplete == False):
			import time
			pos.completionTime = time.time()
		
		vals = [str(elem) for elem in pos.toDict().values()]
		posStr = ",".join(vals)
		f = open('trades.txt', 'a')
		f.write(posStr + "\n")
		f.close()
