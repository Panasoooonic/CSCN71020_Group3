#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "Validation.h"

int* getTriangleSides(int* triangleSides);


int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();
		
		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			//Take triangle sides as input
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);

			//If triangle sides aren't a triangle then give a error message and break
			bool* triangleCheck = isTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			if (!triangleCheck) {
				printf("ERROR: Sides do not make a triangle.");
				break;
			}

			//Print the type of triangle
			char* triangleType = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", triangleType);

			//Get the angles associated with the 3 sides
			/*float* angles = getTriangleAngles(triangleSides[0], triangleSides[1], triangleSides[2]);
			if (angles == NULL) {
				break;
			}*/

			//Print the angles and free memory
			/*for (int i = 0; i < 3; i++) {
				printf("Angle %d: %f\n", i + 1, angles[i]);
			}
			free(angles);*/

			break;

		case 2:
			printf_s("Rectangle selected.\n");

			//Create 2d array to store points of rectangle
			POINT ArrOfPoints[4];

			//Iterate 4 times to take 4 inputs
			//for (int i = 0; i < 4; i++) {
			//	//Take input from user and store it in tmp int array of size 2
			//	POINT* TmpPointPntr = getRectangleSides();
			//	//fill in i point of 2d array with inputted x and y values
			//	ArrOfPoints[i].x = TmpPointPntr->x;
			//	ArrOfPoints[i].y = TmpPointPntr->y;
			//	//Free memory used to temp variable
			//	free(TmpPointPntr);
			//}

			//Sort points into proper order (Top Right) (Bottom Right) (Bottom Left) (Top Left)
			//SortPoints(ArrOfPoints);

			//Test if points form a rectangle.
		/*	if (is_Recatngle(ArrOfPoints)) {
				printf("This is a rectangle with: \n");
				printf("Perameter of: %d\n", get_Peram(ArrOfPoints));
				printf("Area of: %d\n", get_Area(ArrOfPoints));
			}
			else {
				printf("This is not a rectangle");
			}
			break;*/


		case 0:
			continueProgram = false;
			break;
		default:

			 shapeChoice = printShapeMenu();
			continueProgram = false;
			break;
		}
	}
	return 0;
}


void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("0. Exit\n");

	int intInputted;

	bool repeat = true;
	while (repeat)
	{
		char shapeChoice[10];
		int inputValue;
		printf_s("Enter number: ");
		scanf_s("%s", &shapeChoice, 9);
		int isDigit = sscanf(shapeChoice, "%d", &inputValue);

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


int* getTriangleSides(int* triangleSides) {
	bool repeat = true;
	for (int i = 0; i < 3; i++)
	{
		int intInputted;
		while (repeat)
		{
			char input[10];
			int inputValue;
			printf_s("Enter the length of a side of the triangle: ");
			scanf_s("%s", &input, 9);
			int isDigit = sscanf(input, "%d", &inputValue);

			switch (isDigit)
			{
			case 1:
				triangleSides[i] = inputValue;
				repeat = false;
				break;
			default:
				printf_s("Please enter a numeric value\n");
				break;
			}
		}
		repeat = true;
	}

	return triangleSides;
}