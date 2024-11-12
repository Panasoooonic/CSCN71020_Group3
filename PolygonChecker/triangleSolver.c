#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

#define PI 3.14159265

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