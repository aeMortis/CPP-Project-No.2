#pragma once
#include "Karta.h"
#include "Gracz.h"
#include <ctime>
class Kasyno
{
	Karta Cards[52];
	int Check_Card[52];
	int Counter_Card = 0;
	Gracz Players[2];//human
public:
	Kasyno();
	~Kasyno();
	void checkCards(Karta _actual_pointer);
	void tasuj();
	Karta* dajKarte();
	void Graj();
};

