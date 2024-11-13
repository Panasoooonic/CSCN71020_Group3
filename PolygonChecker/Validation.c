#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "Validation.h"


int ValidateStartInput()
{
	int intInputted = 1; // set to 1 so the script plays
	bool repeat = true;
	// Repeat untill correct input is put in
	while (repeat)
	{
		char shapeChoice[10];
		int inputValue;
		printf_s("Enter number: ");
		scanf_s("%s", &shapeChoice, 9);
		int isDigit = sscanf(shapeChoice, "%d", &inputValue); // isDigit is for testing if value inputted can convert to integer or not. (1) - yes

		switch (isDigit)
		{
		case 1:
			if (inputValue == 0 || inputValue == 1 || inputValue == 2)
			{
				intInputted = inputValue;
				repeat = false;
			}
			else
			{
				printf_s("Please select numbers 0 1 or 2");
			}
			break;
		default:
			printf_s("Please enter a numeric value\n");
			break;
		}
	}
	return intInputted;
}

int ValidateTriangleInput()
{
	int intInputted = 1; // set to 1 so the script plays
	bool repeat = true;
	// Repeat untill correct input is put in
	while (repeat)
	{
		char input[10];
		int inputValue;
		printf_s("Enter the length of a side of the triangle: ");
		scanf_s("%s", &input, 9);
		int isDigit = sscanf(input, "%d", &inputValue);// isDigit is for testing if value inputted can convert to integer or not. (1) - yes

		switch (isDigit)
		{
		case 1:
			intInputted = inputValue;
			repeat = false;
			break;
		default:
			printf_s("Please enter a numeric value\n");
			break;
		}
	}
	return intInputted;
}



int ValidateRectangleInput()
{
	int intInputted = 1;	// set to 1 so the script plays
	bool repeat = true;
	// Repeat untill correct input is put in
	while (repeat)
	{
		char input[10];
		int inputValue;
		scanf_s("%s", &input, 9);
		int isDigit = sscanf(input, "%d", &inputValue);// isDigit is for testing if value inputted can convert to integer or not. (1) - yes

		switch (isDigit)
		{
		case 1:
			intInputted = inputValue;
			repeat = false;
			break;
		default:
			printf_s("Please enter a numeric value\n");
			break;
		}
	}
	return intInputted;
}