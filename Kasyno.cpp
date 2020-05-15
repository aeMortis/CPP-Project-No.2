#include "Kasyno.h"
Kasyno::Kasyno()
	: Cards()
	, Player()
	, Check_Card()
{

	for (int i = 0, p = 0; p < 4; p++, i = i + 13) {
		for (int k = 0; k < 13; k++) {
			Cards[i + k].setKolor(p);
			Cards[i + k].setWartosc(k);
		}
	}
	for (int i = 0; i < 52; i++)
		Check_Card[i] = 0;
	tasuj();
}
Kasyno::~Kasyno() {}
Kasyno::Kasyno(const Kasyno& _diff)
	: Check_Card() {
	countPlayers = _diff.countPlayers;
	isBot = _diff.isBot;
	counterCard = _diff.counterCard;
	Player = new Gracz * [countPlayers];
	for (int i = 0; i < 52; i++) {
		Cards[i] = _diff.Cards[i];
		Check_Card[i] = _diff.Check_Card[i];
	}
	for (int i = 0; i < countPlayers - isBot; i++)
		Player[i] = new Gracz;
	for (int i = 0; i < countPlayers-isBot; i++)
		Player[i] = _diff.Player[i];
	for (int i = countPlayers - isBot; i < countPlayers; i++)
		Player[i] = new Bot;
	for (int i = countPlayers - isBot; i < countPlayers; i++)
		Player[i] = _diff.Player[i];
}
void Kasyno::tasuj() {
	Karta temp;
	int change_1, change_2; 
	for (int i = 0; i < 329; i++) 
	{
		change_1 = rand() % 52;
		change_2 = rand() % 52;
		if (change_1 != change_2) {
			temp = Cards[change_1];
			Cards[change_1] = Cards[change_2];
			Cards[change_2] = temp;
		}
	}
} 
void Kasyno::Graj() {
	bool isEnd = false;
	bool play = true;
	int choice;	
	char stop;
	do {
		std::cout << "1. Rozpocznij nowa gre.\n2. Wyjdz.";
		bool check = true;
		std::cin.width(1); 
		choice = inputCheckInt(std::cin);
		switch (choice) {
		case 1:			
			clear_screen(' '); // system('cls'); jest niezbepieczny 
			std::cout << "Wprowadz liczbe wszystkich graczy:";
			do {
				std::cin.width(1);
				countPlayers = inputCheckInt(std::cin);
				if (countPlayers > 1 && countPlayers < 7)
					check = false;
				else std::cout << "Wprowadzono nieprawidlowa"
					<< " liczbe graczy.\n Sprobuj ponownie.";
			} while (check == true);
			check = true;
			std::cout << "Wprowadz liczbe botow:";
			do {
				std::cin.width(1);
				isBot = inputCheckInt(std::cin);
				if (isBot > 0 && isBot < 4) {
					if (countPlayers - isBot > 3) {
						std::cout << "Potrzeba wiecej botow"
							<< ", aby rozpoczac rozgrywke!\n"
							<< "Sprobuj ponownie. :)";
						check == true;
					}
					else if (countPlayers ==3 && isBot == 3) {
						std::cout << "Gra nie sklada sie tylko z graczy komputerowych!\n"
							<< "Zmniejsz liczbe botow, aby rozpoczac rozgrywke. \n";
						check == true;
					}
					else if (countPlayers == 2 && isBot == 2) {
						std::cout << "Gra nie sklada sie tylko z graczy komputerowych!\n"
							<< "Zmniejsz liczbe botow, aby rozpoczac rozgrywke. \n";
						check == true;
					}
					else check = false;
				}
				else std::cout << "Wprowadzono nieprawidlowa"
					<< " liczbe botow.\nMaksymalna ilosc botow to 3"
					<< ", sprobuj ponownie. :)";
			} while (check == true);
			Player = new Gracz * [countPlayers];
			for (int i = 0; i < countPlayers - isBot; i++) {
				Player[i] = new Gracz;
				clear_screen(' ');
				std::cout << "Podaj imie gracza " << i + 1 << ":\n";
				Player[i]->setName();
				startGamePlayer(i);
			}
			for (int i = countPlayers - isBot; i < countPlayers; i++) {
				Player[i] = new Bot;
				clear_screen(' ');
				Player[i]->setBrave();
				startGamePlayer(i);
			}			
			std::cin.get();
			do {
				for (int i = 0; i < countPlayers - isBot; i++) {
					clear_screen(' ');
					Player[i]->ifStand();
					if (Player[i]->doStand() == 0) {
						Player[i]->showCards();
						std::cout << "Twoje punkty wynosza " 
							<< Player[i]->getPointsNumber() << std::endl;
						Player[i]->decide();
						if (Player[i]->doStand() == 0)
							Player[i]->wezKarte(dajKarte());
					}
				}
				for (int i = countPlayers - isBot; i < countPlayers; i++) {
					Player[i]->ifStand();
					if (Player[i]->doStand() == 0)
						Player[i]->wezKarte(dajKarte());
				}
				clear_screen(' ');
				isEnd = checkStand(countPlayers, isBot);
				int *winTab;
				winTab = new int [countPlayers];
				for (int i = 0; i < countPlayers; i++) {
					winTab[i] = Player[i]->getPointsNumber();
				}
				if (isEnd == true) {
					winnersTable(winTab, countPlayers, Player);
					std::cout << "Zapisano rozgrywke w pliku tekstowym. \n"
						<< "Wprowadz dowolny znak i wcisnij enter, aby zakonczyc rozgrywke.";
					std::cin.width(1);
					stop = inputCheckChar(std::cin);
					clear_screen(' ');
				}
				delete[] winTab;				
			} while (isEnd==false);
			for (int i = 0; i < countPlayers; i++) {
				delete Player[i];
			}
			delete Player;
			break;
		case 2:
			play = false;
			break;
		default:
			clear_screen(' ');
			sayIfWrong();
			break;
		}
	} while (play==true);
}
bool Kasyno::checkStand(int _players, int _bots) {
	int* standCheck = new int[_players];
	int counter = 0;					
	bool value = false;
	for (int i = 0; i < _players - _bots; i++)
		standCheck[i] = Player[i]->doStand(); 
	for (int i = _players - _bots; i < _players; i++)
		standCheck[i] = Player[i]->doStand();
	for (int i = 0; i < _players; i++) {
		if (standCheck[i] == 1)
			counter++;
	}
	if (counter == _players) { 
		std::cout << "Wszyscy gracze spasowali! Koniec rozgrywki.\n";
		saveGame();
		value = true;
	}
	delete[] standCheck;
	return value;
}
void Kasyno::saveGame() {
	std::ofstream file;
	file.open("results.txt", std::ifstream::app);
	if (file.is_open()) {}
	else file.open("results.txt", std::ifstream::out);
	for (int i = 0; i < countPlayers; i++) {
		file.width(20);
		file.setf(std::ios::left);
		file << Player[i]->giveName();
		for (int k = 0; k < Player[i]->getCardsNumber(); k++) {
			file.width(1);
			file << std::left << Player[i]->giveCardsColor(k) 
				<< std::left << Player[i]->giveCardsFigure(k) << " ";
		}
		// problem - po pierwszym wywolaniu giveCardsColor bylo wypelniane
		// spacjami do konca i uzupelniany tekst od prawej
		// nie udalo mi sie uporac z tym, w zaden inny sposob
		file.width(30 - (Player[i]->getCardsNumber() * 3));
		file << " ";
		file.unsetf(std::ios::left);
		file.width(10);
		file.setf(std::ios::right);
		file << Player[i]->getPointsNumber() << std::endl;
		file.unsetf(std::ios::right);
	}
	file << "\n";
	file.close();
}
void Kasyno::startGamePlayer(int _which) {
	Player[_which]->wezKarte(dajKarte());
	Player[_which]->wezKarte(dajKarte());	
} 
void Kasyno::sayIfWrong() {
	std::cout << "Ot Ty wariacie! :) W kasynie"
		<< " nie ma takiej opcji!\n"
		<< "Sprobuj ponownie.\n";
}
void Kasyno::winnersTable(int _tab[], int _countPlayers, Gracz** _player) {
	int keep_x = 0, keep_y = 0, keep_z = 0, keep_w = 0
		, isOneWinner = 0, isNullT = 0, isNullN = 0, isNullC = 0, checker;
	Gracz *listT[6], *listN[6], *listC[6], *listCT[6];
	for (int i = 0; i < 6; i++) {
		listT[i] = nullptr;
		listN[i] = nullptr;
		listC[i] = nullptr;
	}
	for (int i = 0; i < _countPlayers; i++) {
		if (_player[i]->getPointsNumber() == 21)
			listT[keep_x++] = _player[i];
		else if (_player[i]->getPointsNumber() > 21)
			listN[keep_z++] = _player[i];
		else if (_player[i]->getPointsNumber() < 21)
			listC[keep_y++] = _player[i];
	}
	for (int i = 0; i < 6; i++) {
		if (listT[i] != nullptr)
			isOneWinner++;
		else isNullT++;
		if (listN[i] == nullptr)
			isNullN++;
		if (listC[i] == nullptr)
			isNullC++;
	}
	if (isOneWinner == 1)
		std::cout << "Gracz "<< listT[0]->giveName() << " wygral gre!\n";
	else if (isOneWinner > 1) {
		std::cout << "Gracze ";
		for (int i = 0; i < 6-isNullT; i++)
			std::cout << listT[i]->giveName() << " ";
		std::cout << " wygrali ex eaquo.\n";
			}	
	if (isOneWinner == 0 && isNullC != 6) {
		checker = listC[0]->getPointsNumber();
		for (int i = 0; i < 6-isNullC; i++) {
			if (checker < listC[i]->getPointsNumber())
				checker = listC[i]->getPointsNumber();
		}
		for (int i = 0; i < 6-isNullC; i++) {
			if (checker == listC[i]->getPointsNumber())
				listCT[keep_w++] = listC[i];
		}
		if (keep_w == 1)
			std::cout << "Gracz " << listCT[0]->giveName() 
			<< " wygral posiadajac " << listCT[0]->getPointsNumber() 
			<< " punktow!\n";
		else if (keep_w > 1) {
			std::cout << "Gracze ";
			for (int i = 0; i < keep_w; i++)
				std::cout << listCT[i]->giveName() << " ";
			std::cout << " wygrali ex eaquo.\n";
				
		}
	}
	if (isNullC == 6 && isOneWinner == 0) std::cout 
		<< "Wszyscy gracze przegrali posiadajac powyzej 21 punktow.\n";
	
}
Karta* Kasyno::dajKarte() {
	Karta* pointer;
	int which, i = 0, leave = 0;
	do {
		which = rand() % 52;
		if (&Cards[which] == Check_Card[which]) {
			leave++;
			if (counterCard > 51)
				leave = 0;
		}
		else {
			Check_Card[which] = &Cards[which];
			leave = 0;
			counterCard++;
		}
	} while (leave != 0);
	pointer = &Cards[which];
	return pointer;
}