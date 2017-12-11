class BFX(object):
	def __init__(self, quantity, key, secret):
		self.quantity = quantity
		self.commission = .2

		from bitfinex.client import Client, TradeClient
		self.privateWrapper = TradeClient(key, secret)
		self.publicWrapper = Client()

	def getCommission(self):
		return self.commission

	def getSpotPrice(self, ticker='btcusd'): 
		return self.publicWrapper.ticker(ticker)['last_price']

	def goLong(self): 
		price = self.getSpotPrice()
		order = self.privateWrapper.place_order(self.quantity, price, 'buy', 'exchange market')
		import time 
		time.sleep(.25)
		