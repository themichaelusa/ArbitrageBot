from Bot import Bot
if __name__ == "__main__":
	GDAX_KEYS = ["REPLACE", "REPLACE", "REPLACE"]
	CEX_KEYS = ["REPLACE", "REPLACE", "REPLACE"]

	GDAX_KEY = '728c0c21a83fd8232eeef2f6f2bb2580'
	GDAX_SECRET = 'oryvFvYoo/kqQ2d/djNyqo7glrKXqCgQeLi2KIjQiVTNx6c66sjmcKFl9pDDYe0Y7iKk1IidSEuRcj4Mu31eBg=='
	GDAX_PASSPHRASE = 'z6wdnzrkk6'

	from GDAX_API import GDAX 
	from CEX_API import CEX

	testGDAX = GDAX(.0001, GDAX_KEY, GDAX_SECRET, GDAX_PASSPHRASE)

	CEX_USERNAME = 'shovik.guha@gmail.com' 
	CEX_KEY = 'yhlHM9mqjuC6ip4FQ8JwRleO30I'
	CEX_SECRET = 'dWu16uMpuu1P6aXsXa5cpht4AAA'
	testCEX = CEX(.0001, CEX_USERNAME, CEX_KEY, CEX_SECRET)
	print(testCEX.api.trade_history())
	print(testGDAX.auth.get_accounts())
	print(testCEX.getSpotPrice())
	"""
	bot = Bot(.01, GDAX_KEYS, CEX_KEYS)
	bot.start(numTrades=1)	
	"""
