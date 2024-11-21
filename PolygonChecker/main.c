#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "main.h"
#include "triangleSolver.h"
#include "Validation.h"

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
			// Take triangle sides as input

			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			// If triangle sides aren't a triangle then give an error message and break

			bool triangleCheck = isTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			if (!triangleCheck) {
				printf("ERROR: Sides do not make a triangle.\n");
				break;
			}

			// Print the type of triangle
			char* triangleType = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", triangleType);

			// Get the angles associated with the 3 sides

			float angles[3];
			calculateAngles(triangleSides[0], triangleSides[1], triangleSides[2], angles);

			// Print the angles
			for (int i = 0; i < 3; i++) {
				printf("Angle %d: %.2f\n", i + 1, angles[i]);
			}

            break;

		case 2:
			printf_s("Rectangle selected.\n");
			printf_s("Please enter 4 (x,y) points to create the rectangle.\n");

			// Create 2d array to store points of rectangle
			POINT ArrOfPoints[4];
			// Iterate 4 times to take 4 inputs
			for (int i = 0; i < 4; i++) {
				//Take input from user and store it in tmp int array of size 2
				int* TmpPointPntr = getRectanglePoints();
				// Fill in i point of 2d array with inputted x and y values
				ArrOfPoints[i].x = *(TmpPointPntr + 0);
				ArrOfPoints[i].y = *(TmpPointPntr + 1);
				printf("%d %d\n", ArrOfPoints[i].x, ArrOfPoints[i].y);
				// Free memory used to temp variable
				free(TmpPointPntr);
			}

			// Check if 4 points are able to shape a valid rectangular
			bool isRectangular = checkIfRectangular(ArrOfPoints);
			if (isRectangular) {
				printf("These 4 points are able to shape a valid rectangular.\n");

				// Print out the rectangular permieter
				double perimeter = getRectanglePerimeter(ArrOfPoints);
				printf("The perimeter of rectangular is: %.3f\n", perimeter);

				// Print out the rectangular area
				double area = getRectangleArea(ArrOfPoints);
				printf("The perimeter of rectangular is: %.3f\n", area);
			}
			else {
				printf("4 given points cannot shape a rectangular!\n");
			}
			break;

            // Additional rectangle processing can be added here

            break;

        case 0:
            continueProgram = false;
            break;
        default:
            printf_s("Invalid value entered.\n");
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
    printf_s("0. Exit\n");
    printf_s("1. Triangle\n");
    printf_s("2. Rectangle\n");
    printf_s("Enter a number: ");
    int intInputted = ValidateStartInput();

    return intInputted;
}

int* getTriangleSides(int* triangleSides) {
    for (int i = 0; i < 3; i++) {
        printf_s("Enter the length of a side of the triangle: ");
        int intInputted = ValidateInput();
        triangleSides[i] = intInputted;
    }
    return triangleSides;
}

int* getRectanglePoints() {
    int* inputArray = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            printf_s("Enter the x value: ");
        } else if (i == 1) {
            printf_s("Enter the y value: ");
        }
        int intInputted = ValidateInput();
        *(inputArray + i) = intInputted;
    }
    return inputArray;
}