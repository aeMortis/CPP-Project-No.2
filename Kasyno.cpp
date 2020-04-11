#include "Kasyno.h"
#include <ctime>
Kasyno::Kasyno()
	: Cards()
	, Players()
{
	for (int i = 0, p = 0; p < 4; p++, i = i + 13) {
		for (int k = 0; k < 13; k++) {
			Cards[i + k].setKolor(p);
			Cards[i + k].setWartosc(k);
		}
	}
	tasuj();
	std::cout << "Kontruktor kasyna! ";
} 
// dziala poprawnie
void Kasyno::tasuj() {
	srand((int)time(NULL));
	Karta temp;
	int change_1, change_2; 
	for (int i = 0; i < 1337; i++) 
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
// dziala poprawnie
Karta* Kasyno::dajKarte() {
	srand((int)time(NULL)); // bardziej losowo
	Karta* pointer; // wskaznij do przekazania
	int which, i = 0, leave=0; 
	do {
		which = rand() % 52; // losuj jedna z 52 
		for (int x = 0; x < 52; x++) { // sprawdza kolejne komorki w tablicy
			if (Check_Card[x] == (int)&Cards[which])		// sprawdz czy wartosc int w tablicy == int pointera
				i++;		// zwieksz i jesli tak
		}
		if (i == Counter_Card) { // gdy wyjdziesz z for'a 
			Check_Card[Counter_Card] = (int)&Cards[which]; // przypisz wartosc ze wskaznika 
			std::cout << Check_Card[Counter_Card] << " <- check || cards -> "; // test
			std::cout << (int)&Cards[which] << "\n"; // test
			Counter_Card++; // zwieksz liczydelko 
			std::cout << "T\t"; // test
		}
		else if (Counter_Card==52) { // wyjscie gdy wszystkie zapelnione
			leave = 0;
		}
		else { // zwieksza licznik wewnetrzny by wykonac ponownie
			leave++;
			std::cout << "N ";
		}
	} while (leave!=0);
	pointer = &Cards[which]; 
	return pointer; // przekazanie adresu 
}

void Kasyno::Graj() {
}
Kasyno::~Kasyno() {
	std::cout << "Destruktor kasyna!\n";
}
void Kasyno::checkCards(Karta _actual_pointer) {

}