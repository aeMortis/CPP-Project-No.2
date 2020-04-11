#pragma once
#include "Karta.h"
class Gracz
{
	Karta* Cards;
	int cardsCount;
	int pointsCount;
public:
	Gracz();
	~Gracz();
	Gracz(const Gracz& _copy);
	void wezKarte(Karta* _karta);
	void showCards();
	Karta* addCardToHand();
};

