#include "checkFunction.h"

int inputCheckInt(std::istream& _value) {
	int check;
		_value >> check;
		if (std::cin.fail() == true) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	return check;
}
char inputCheckChar(std::istream& _value) {
	char check;
		_value >> check;
		if (std::cin.fail() == true) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	return check;
}