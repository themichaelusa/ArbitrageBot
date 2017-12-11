class GDAX(object):

	def __init__(self, quantity, key, secret, passphrase):
		import gdax
		self.commission = .25
		self.quantity = quantity
		self.public = gdax.PublicClient()
		self.auth = gdax.AuthenticatedClient(key, secret, passphrase)

	def getCommission(self):
		return self.commission

	def getSpotPrice(self, ticker='BTC-USD'): 
		return self.public.get_product_ticker(product_id=ticker)['price']

	def goLong(self): 
		response = dict(self.auth.buy(product_id=self.symbol, type='market', funds=self.quantity)) 
		import time 
		time.sleep(.25)

		