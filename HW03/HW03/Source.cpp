#include <iostream>
#include <stdexcept>
#include "ReadInt.h"


int main() {
	int low=0, high=0;
	std::cout << "Enter the range of values to read.\n";
	std::cout << "high: ";
	std::cin >> high;
	std::cout << "\nlow: ";
	std::cin >> low;
	std::cout << "\n";
	try {
		int number = read_int("Please enter a number within the range: ", low, high);
		std::cout << "\nYou entered " << number << '\n';
	}
	catch(std::invalid_argument &e) {
		std::cerr << "Exception: You supplied an invalid argument for read_int!\n";
	}
	return 0;
}