#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

#include "rectangleSolver.h"

void swapTwoPoints(POINT points[4], int point1, int point2)
{
	POINT tempPoint = points[point1];
	points[point1] = points[point2];
	points[point2] = tempPoint;
}

double* getTwoRectangleEdges(POINT points[4]) {
	double* twoEdges = (double*)malloc(2 * sizeof(double));

	if (twoEdges == NULL) {
		printf("Error at getTwoRectangleEdges function:\n");
		printf("Cannot create dynamic memory allocation!\n");
		exit(0);
		return;
	}

	// Calculate vector value between 2 points
	POINT vector1 = { points[0].x - points[1].x, points[0].y - points[1].y };		// Calculate the vector between point1 & point2
	POINT vector2 = { points[0].x - points[3].x,  points[0].y - points[3].y };		// Calculate the vector between point1 & point4

	// Calculate the length of two vectors
	twoEdges[0] = sqrt(vector1.x * vector1.x + vector1.y * vector1.y);
	twoEdges[1] = sqrt(vector2.x * vector2.x + vector2.y * vector2.y);

	return twoEdges;
}

double getRectanglePerimeter(POINT points[4])
{
	double* twoEdges = getTwoRectangleEdges(points);
	double result = (twoEdges[0] + twoEdges[1]) * 2;
	free(twoEdges);
	return result;
}

double getRectangleArea(POINT points[4])
{
	double* twoEdges = getTwoRectangleEdges(points);
	double result = twoEdges[0] * twoEdges[1];
	free(twoEdges);
	return result;
}

bool checkIfRectangular(POINT points[4]) {
	bool isRectangular = true;

	for (int i = 0; i < 4; i++) {
		POINT currPoint = points[i];
		POINT point1, point2, point3;
		switch (i) {
		case 0:
			point1 = points[1];
			point2 = points[2];
			point3 = points[3];
			break;
		case 1:
			point1 = points[0];
			point2 = points[2];
			point3 = points[3];
			break;
		case 2:
			point1 = points[0];
			point2 = points[1];
			point3 = points[3];
			break;
		case 3:
			point1 = points[0];
			point2 = points[1];
			point3 = points[2];
			break;
		}

		// Calculate vector value between 2 points
		POINT vector1 = { currPoint.x - point1.x, currPoint.y - point1.y };		// Calculate the vector between currPoint & point1
		POINT vector2 = { currPoint.x - point2.x, currPoint.y - point2.y };		// Calculate the vector between currPoint & point2
		POINT vector3 = { currPoint.x - point3.x, currPoint.y - point3.y };		// Calculate the vector between currPoint & point3

		// Calculate the scalar product between 2 vectors
		int scalarProduct1 = vector1.x * vector2.x + vector1.y * vector2.y;		// Calculate scalar product between vector1 & vector2
		int scalarProduct2 = vector1.x * vector3.x + vector1.y * vector3.y;		// Calculate scalar product between vector1 & vector2
		int scalarProduct3 = vector2.x * vector3.x + vector2.y * vector3.y;		// Calculate scalar product between vector1 & vector2

		// Find the square "corner" for this point
		bool isSquareAngle = scalarProduct1 == 0 || scalarProduct2 == 0 || scalarProduct3 == 0;
		isRectangular &= isSquareAngle;

		// Swap two points to reorder a valid sequence to shape a rectangular
		if (i == 3) {
			if (scalarProduct1 == 0) swapTwoPoints(points, 0, 3);
			if (scalarProduct3 == 0) swapTwoPoints(points, 2, 3);
		}
	}
	
	return isRectangular;
}
