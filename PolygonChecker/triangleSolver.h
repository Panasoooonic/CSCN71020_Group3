#pragma once
#ifndef TRIANGLE_SOLVER_H
#define TRIANGLE_SOLVER_H 
char* analyzeTriangle(int side1, int side2, int side3);
bool* isTriangle(int side1, int side2, int side3);
void calculateAngles(int side1, int side2, int side3, float* angles);

#endif // !TRIANGLE_SOLVER_H