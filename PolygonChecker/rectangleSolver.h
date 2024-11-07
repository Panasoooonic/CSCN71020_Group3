#pragma once

#include <stdbool.h>

typedef struct point {
	int x;
	int y;
} POINT;


bool is_Rectangle(POINT* points);
int get_Peram(POINT* arrOfPoints);
int get_Area(POINT* arrOfPoints);
int get_Distance(POINT pointA, POINT pointB);
bool is_Orthogonal(POINT pointA, POINT pointB, POINT pointC, POINT pointD);
void Sort_Points(POINT* arrOfPoints);



