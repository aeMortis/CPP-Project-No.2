#include "Bot.h"
int Bot::numberOfBots = 0;
Bot::Bot()
	: brave()
	, Gracz() {
	setName();
	if (numberOfBots == 2)
		numberOfBots = 0;
	else
	numberOfBots++;
}
Bot::~Bot() {}
Bot::Bot(const Bot& _diff) 
: Gracz(_diff) {
	brave = _diff.brave;
}
void Bot::setName() {
	char botName[4] = "Bot";
	botName[3] = 49+numberOfBots;
	for (int i = 0; i < 4; i++)
		name[i] = botName[i];
} 
void Bot::setBrave() {
	std::cout << "Wybierz poziom trudnosci gracza " << giveName() 
		<< ".\n1. Zachowawczy.\n2. "
		<< "Normalny.\n3. Ryzykujacy.\n";
	int check;
	do {
		std::cin.width(1);
		check = inputCheckInt(std::cin);
		if (check > 3 || check < 1) {
			std::cout << "Nie ma takiej trudnosci! :)"
				"\nSprobuj ponownie.";
		}
	} while (check < 1 || check>3);
	brave = check;
}
void Bot::showCards() {
	std::cout << giveName() << " - moje karty: \n";
	for (int i = 0; i < cardsCount; i++)
		std::cout << "Figura: " << Cards[i].getFigura()
		<< " Kolor: " << (int)Cards[i].getKolor() << "\n";
}
void Bot::ifStand() {
	if (brave == 1)
		if (pointsCount <= limit[0]) {}
		else stand = 1;
	else if (brave == 2)
		if (pointsCount <= limit[1]) {}
		else stand = 1;
	else if (brave == 3)
		if (pointsCount <= limit[2]) {}
		else stand = 1;
}
char* Bot::giveName() {
	return name;
}