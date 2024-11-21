#pragma once

#include <stdbool.h>

typedef struct point {
	int x;
	int y;
}POINT;


bool checkIfRectangular(POINT points[4]);
void swapTwoPoints(POINT points[4], int point1, int point2);
double getRectanglePerimeter(POINT points[4]);
double getRectangleArea(POINT points[4]);
double* getTwoRectangleEdges(POINT points[4]);
