all: main.cpp Bot.h Bot.cpp ExchangeAPI/ExchangeWrapper.cpp ExchangeAPI/ExchangeWrapper.h
	clang++ -g -Wall -Wextra -std=c++11 main.cpp Bot.h Bot.cpp ExchangeAPI/ExchangeWrapper.cpp ExchangeAPI/ExchangeWrapper.h

clean: 
