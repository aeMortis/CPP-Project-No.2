#include <iostream>
#include "Kasyno.h"
#include "Karta.h"
#include "Gracz.h"
#include "Bot.h"

int main()
{
 	srand((int)time(NULL));
	Kasyno casino;
	casino.Graj();
	std::cin.get();
	return 0;
}