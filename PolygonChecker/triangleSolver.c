#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

#define PI 3.14159265

bool* isTriangle(int side1, int side2, int side3)
{
    bool* result = true;
    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        result = false;
    }
    else if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
        result = false;
    }
    return result;
}


char* analyzeTriangle(int side1, int side2, int side3) {
    char* result = "";
    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        result = "Not a triangle";
    }
    else if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
        result = "Not a triangle";
    }
    else if (side1 == side2 && side1 == side3) {
        result = "Equilateral triangle";
        printf("The triangle is a perfect triangle.\n");
        printf("All angles are 60 degrees.\n");
    }
    else if ((side1 == side2 && side1 != side3) || 
             (side1 == side3 && side1 != side2) || 
             (side2 == side3 && side2 != side1)) {
        result = "Isosceles triangle";
    }
    else {
        result = "Scalene triangle";
    }

    return result;
}


void calculateAngles(int side1, int side2, int side3, float* angles) {
    angles[0] = acos((float)(side2 * side2 + side3 * side3 - side1 * side1) / (2.0 * side2 * side3)) * 180.0 / PI;
    angles[1] = acos((float)(side1 * side1 + side3 * side3 - side2 * side2) / (2.0 * side1 * side3)) * 180.0 / PI;
    angles[2] = acos((float)(side1 * side1 + side2 * side2 - side3 * side3) / (2.0 * side1 * side2)) * 180.0 / PI;
}