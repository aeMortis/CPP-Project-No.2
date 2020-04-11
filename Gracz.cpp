#include "Gracz.h"

void Gracz::wezKarte(Karta* _karta)
{
	/*if (cardsCount == 10)
		std::cout << "Cannot pick more cards!\n";
	else {
		addCardToHand();
		Cards[cardsCount-1] = *_karta;
	}*/
}
//Karta* Gracz::addCardToHand() {
//	Karta* tempCards = new Karta[cardsCount];
//	for (int i = 0; i < cardsCount; i++)
//		tempCards[i] = Cards[i];
//	delete[] Cards;
//	cardsCount++;
//	Cards = new Karta[cardsCount];
//	for (int i = 0; i < cardsCount-1; i++)
//		Cards[i] = tempCards[i];
//	delete[] tempCards;
//	return Cards;
//}
Gracz::Gracz()
/*: Cards(nullptr) 
, cardsCount()
, pointsCount()*/ {
	std::cout << "Konstruktor gracza! \n";
}
Gracz::Gracz(const Gracz& _copy) {
	/*cardsCount = _copy.cardsCount;
	Cards = new Karta[cardsCount];
	for (int i = 0; i < cardsCount; i++) 
		Cards[i] = _copy.Cards[i];*/
}
Gracz::~Gracz() {
	std::cout << "Destruktor gracza!\n";
}
void Gracz::showCards() {
	/*for (int i = 0; i < cardsCount; i++)
		std::cout << &Cards[i] << "\t";
	std::cout << "\n";*/
}