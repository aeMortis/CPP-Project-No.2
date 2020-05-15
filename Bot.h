#pragma once
#include "Gracz.h"
class Kasyno;
class Bot : public Gracz {
	int limit[3] = { 13,15,18 };
	int brave;
	static int numberOfBots;
public:
	friend int inputCheckInt(std::istream& _value);
	Bot();
	~Bot();
	Bot(const Bot& _dfiff);
	void setName();
	void setBrave();
	void showCards();
	void ifStand();
	char* giveName();
};

