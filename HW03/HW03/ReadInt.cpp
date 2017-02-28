#include <ios>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include "ReadInt.h"
#include "ReadInt.h"

int read_int(const std::string &prompt, int lowerBound, int upperBound) {
	//Causes the cin stream to throw an ios_base::failure exception on input error
	std::cin.exceptions(std::ios_base::failbit);
	int num = 0;
	while (true) {//Loop until valid input
		try {
			if (upperBound <= lowerBound) {
				throw std::invalid_argument("The range of integers is empty");
			}
			std::cout << prompt;
			std::cin >> num;
			if (num < lowerBound) {
				throw std::out_of_range("Your input of " + std::to_string(num) + " is less than the lower limit of " + std::to_string(lowerBound));
			}
			else if (num > upperBound) {
				throw std::out_of_range("Your input of " + std::to_string(num) + " is greater than the upper limit of " + std::to_string(upperBound));
			}
			return num;
		}
		catch (const std::ios_base::failure &ex) {
			std::cout << "Bad numeric string -- try again.\n";
			std::cin.clear(); //Reset error flag
			std::cin.ignore(std::numeric_limits<int>::max(), '\n'); //Skip current input line
		}
		catch (const std::out_of_range &ex) {
			std::cerr << "Exception: you supplied an input that was out of range: " << ex.what() << '\n';
		}
	}
	return 0;
}