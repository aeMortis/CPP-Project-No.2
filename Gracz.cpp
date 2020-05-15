#include "Gracz.h"
#include "Kasyno.h"
Gracz::Gracz() 
: Cards() 
, cardsCount()
, pointsCount() 
, stand()
, name() {}
Gracz::Gracz(const Gracz& _copy)
	: name() {
	cardsCount = _copy.cardsCount;
	pointsCount = _copy.pointsCount;
	stand = _copy.stand;
	for (int i = 0; i < 20; i++)
		name[i] = _copy.name[i];
	Cards = new Karta[cardsCount];
}
Gracz::~Gracz() {}
int Gracz::doStand() { 
	return stand;
}
int Gracz::getPointsNumber() { 
	return pointsCount;
}
int Gracz::getCardsNumber() {
	return cardsCount;
}
char Gracz::giveCardsColor(int _number) {
	char name = {};
	if (Cards[_number].getKolor() == 3)
		name = 'c';
	else if (Cards[_number].getKolor() == 4)
		name = 'd';
	else if (Cards[_number].getKolor() == 5)
		name = 'z';
	else if (Cards[_number].getKolor() == 6)
		name = 'w';
	return name;
}
// oznaczenia liczbowe zamiast znakow 
char Gracz::giveCardsFigure(int _number) {
	return Cards[_number].getFigura();
}
char* Gracz::giveName() {
	return name;
}
void Gracz::wezKarte(Karta* _karta) {
	if (cardsCount == 10) {
		std::cout << "Nie mozna pobrac wiecej kart!\n";
	}
	else {
		Cards = _karta;
		pointsCount += _karta->getWartosc();
		if (pointsCount > 20)
			stand = 1;
		cardsCount++;
	}
}
void Gracz::showCards() {
	std::cout << giveName() << " - moje karty: \n";
	for (int i = 0; i < cardsCount; i++)
		std::cout << "Figura: " << Cards[i].getFigura()
		<< " Kolor: " << (int)Cards[i].getKolor() << "\n";
}
void Gracz::ifStand() {
	if (doStand() == 1)
		std::cout << "Gracz " << giveName() << " spasowal.\n";
	else if (doStand() == 0)
		std::cout << "Gracz " << giveName() << " Twoja kolej. \n";
}
void Gracz::decide() {
	std::cout << "Czy chcesz spasowac?\nWybierz tak badz nie. (t/n)\n";
	char check;
	bool statement;
	do {
		std::cin.width(1);
		check = inputCheckChar(std::cin);
		if (check == 't' || check == 'T') {
			stand = 1;
			statement = 1;
		}
		else if (check == 'n' || check == 'N') {
			stand = 0;
			statement = 1;
		}
		else {
			std::cout << "Nie ma takiej odpowiedzi!"
				<< " Sprobuj ponownie. (t/n)\n";
			statement = 0;
		}
	} while (statement == false);
}
void Gracz::setName() {
	std::cout << "Wprowadz imie gracza.\n";
	std::cin.width(21);
	std::cin >> name;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void Gracz::showPoints() {
	std::cout << "Gracz " << giveName() 
		<< " posiada: " << getPointsNumber() << " punktow." << std::endl;
}
