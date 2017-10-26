#include "Bot.h"

int main(int argc, char const *argv[]){
	Bot b("BFX", "CEX", .01);
	b.startBot(100);
	return 0;
}