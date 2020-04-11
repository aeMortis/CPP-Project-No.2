#include <iostream>
#include "Kasyno.h"
int main()
{
	Kasyno casino;
	for (int i = 0; i < 100; i++) {
		std::cout << "\n" << i << ". ";
		casino.dajKarte();
	}
	
	std::cin.get();
	return 0;
}