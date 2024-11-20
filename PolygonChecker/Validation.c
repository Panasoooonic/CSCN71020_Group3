#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "Validation.h"


int Validation()	// primary Validation function
{
	char input[10];
	scanf_s("%s", &input, 9);	// accept string input
	int inputValue = atof(&input);	// convert to integer
	return inputValue;
}


int ValidateStartInput()
{
	int intInputted = 1; // set to 1 so the script plays
	bool repeat = true;
	// Repeat untill correct input is put in
	while (repeat)
	{
		int inputValue = Validation();

		if (inputValue == 0 || inputValue == 1 || inputValue == 2)
		{
			intInputted = inputValue;
			repeat = false;
		}
		else
		{
			printf_s("Please select numbers 0 1 or 2");
		}
	}
	return intInputted;
}

int ValidateInput()
{
	int intInputted = 1;	// set to 1 so the script plays
	bool repeat = true;
	// Repeat untill correct input is put in
	while (repeat)
	{
		int inputValue = Validation();

		if (inputValue >= 1)
		{
			intInputted = inputValue;
			repeat = false;
		}
		else
		{
			printf("Please enter a numeric value or a value greater than or equal to 1: ");
		}
	}
	return intInputted;
}