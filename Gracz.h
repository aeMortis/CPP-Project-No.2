#pragma once
#include "Karta.h"
#include "checkFunction.h"
class Kasyno; 
class Gracz {
protected:
	Karta* Cards; 
	int cardsCount = 0; 
	int pointsCount = 0;
	int stand = 0; 
	char name[20];
public:
	friend int inputCheckInt(std::istream& _value);
	friend char inputCheckChar(std::istream& _value);
	Gracz();
	Gracz(const Gracz& _copy);
	~Gracz();
	int doStand(); 
	int getPointsNumber();
	int getCardsNumber();
	char giveCardsColor(int _number);
	char giveCardsFigure(int _number);
	virtual char* giveName();
	void wezKarte(Karta* _karta);
	virtual void showCards(); 
	virtual void ifStand(); 
	void decide();
	virtual void setName();
	virtual void setBrave() {};
	void showPoints();
};

