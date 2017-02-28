#ifndef _ReadInt_H
#define _ReadInt_H

#include <string>

/*
	Function to return an integer in response to user input. The user is 
	prompted for an integer input. If they enter a non-number, the input is discarded
	and they are prompted to try again.

	@param prompt: the message requesting input from the user
	@return: the first valid data value
*/
int read_int(const std::string &prompt, int lowerBound, int upperBound);

#endif // !_ReadInt_H