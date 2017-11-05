
EXCHANGE = ExchangeAPI/ExchangeAPI.cpp ExchangeAPI/Bitfinex_API.cpp ExchangeAPI/CEX_API.cpp ExchangeAPI/ExchangeWrapper.cpp 
EFLAGS = -Wall -Wextra 

all: main.cpp Bot.cpp Position/Position.cpp $(ExchangeFiles)
	clang++ -g $(EFLAGS) -std=c++11 main.cpp Bot.cpp Position/Position.cpp $(ExchangeFiles)
	
clean: 
