#pragma once
#include "Karta.h"
#include <ctime>
#include "Gracz.h"
#include "Bot.h"
#include "checkFunction.h"
#include <fstream>
#include <stdlib.h>
#include "clear.h"
class Gracz;
class Bot;
class Kasyno {
	Karta Cards[52];
	Karta *Check_Card[52];
	Gracz **Player;
	int counterCard = 0; 
	int countPlayers=0, isBot; 
public:
	friend int inputCheckInt(std::istream& _value); 
	friend char inputCheckChar(std::istream& _value);
	Kasyno();
	Kasyno(const Kasyno& _diff);
	~Kasyno();
	void tasuj();
	void Graj(); 
	bool checkStand(int _players, int _bots); 
	void saveGame(); 
	void startGamePlayer(int _which); 
	void sayIfWrong(); 
	void winnersTable(int _tab[], int _countPlayers, Gracz** _player);
	Karta* dajKarte(); 
};

