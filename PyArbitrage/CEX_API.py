class CEX(object):
	def __init__(self, quantity, username, key, secret):
		self.quantity = quantity
		self.commission = .2

		import cexio
		self.api = cexio.Api(username, key, secret)

	def getCommission(self):
		return self.commission

	def getSpotPrice(self): 
		return float(self.api.last_price()['lprice'])

	def goShort(self): 
		price = self.getSpotPrice()
		stop = self.getSpotPrice()*.98
		self.api.open_short_position(self.quantity, 'BTC/USD', price, stop)

		