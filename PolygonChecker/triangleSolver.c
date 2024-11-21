#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

#define PI 3.14159265

bool isTriangle(int side1, int side2, int side3) {
    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        return false;
    }
    if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
        return false;
    }
    return true;
}

void calculateAngles(int side1, int side2, int side3, float* angles) {
    angles[0] = acos((float)(side2*side2 + side3*side3 - side1*side1) / (2.0 * side2 * side3)) * 180.0 / PI;
    angles[1] = acos((float)(side1*side1 + side3*side3 - side2*side2) / (2.0 * side1 * side3)) * 180.0 / PI;
    angles[2] = acos((float)(side1*side1 + side2*side2 - side3*side3) / (2.0 * side1 * side2)) * 180.0 / PI;
}

char* analyzeTriangle(int side1, int side2, int side3) {
    char* result = "";
    if (!isTriangle(side1, side2, side3)) {
        result = "Not a triangle";
    }
    else if (side1 == side2 && side1 == side3) {
        result = "Equilateral triangle";
    }
    else if ((side1 == side2 && side1 != side3) || 
             (side1 == side3 && side1 != side2) || 
             (side2 == side3 && side2 != side1)) {
        result = "Isosceles triangle";
    }
    else {
        result = "Scalene triangle";
    }

    float angles[3];
    calculateAngles(side1, side2, side3, angles);
    printf("Angles of the triangle are: %.2f, %.2f, %.2f\n", angles[0], angles[1], angles[2]);

    return result;
}
