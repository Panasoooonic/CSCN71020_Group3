#include "pch.h"
#include <stdbool.h>
#include "CppUnitTest.h"

extern "C" char* analyzeTriangle(int side1, int side2, int side3);
extern "C" bool* isTriangle(int side1, int side2, int side3);
extern "C" void calculateAngles(int side1, int side2, int side3, float* angles);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TriangleSolverUnitTests
{
	TEST_CLASS(TriangleSolverUnitTests)
	{
	public:
		
        // Verifies that an equilateral triangle is correctly identified as a triangle.
        TEST_METHOD(isTriangle_Identical_Sides_Return_True)
        {
            bool* result = isTriangle(3, 3, 3);  // Equilateral triangle (all sides are equal)
            Assert::IsTrue(result);  // Expecting true since it's a valid triangle
        }

        // Checks that invalid sides that don't form a triangle return false.
        TEST_METHOD(isTriangle_Invalid_Sides_Return_False)
        {
            bool* result = isTriangle(1, 1, 3);  // Invalid triangle (sides don't satisfy the triangle inequality)
            Assert::IsFalse(result);  // Expecting false because these sides can't form a valid triangle
        }

        // Checks that identical sides classify the triangle as equilateral.
        TEST_METHOD(analyzeTriangle_Identical_Sides_Return_Equilateral)
        {
            char* result = analyzeTriangle(3, 3, 3);  // Equilateral triangle
            Assert::AreEqual("Equilateral triangle", result);  // Expecting "Equilateral"
        }

        // Tests a scalene triangle with different side lengths.
        TEST_METHOD(analyzeTriangle_Different_Sides_Return_Scalene)
        {
            char* result = analyzeTriangle(3, 4, 5);  // Scalene triangle (all sides different)
            Assert::AreEqual("Scalene triangle", result);  // Expecting "Scalene"
        }

        // Calculates angles for an equilateral triangle and checks that all are 60 degrees.
        TEST_METHOD(calculateAngles_Identical_Sides_All_60)
        {
            float angles[3];
            calculateAngles(3, 3, 3, angles);
            Assert::AreEqual(60.0f, angles[0], 0.1f);  // All angles in an equilateral triangle should be 60°
            Assert::AreEqual(60.0f, angles[1], 0.1f);
            Assert::AreEqual(60.0f, angles[2], 0.1f);
        }

        // Calculates the angles for a right triangle (3-4-5 triangle).
        TEST_METHOD(calculateAngles_Different_Sides_Calculate_Angles)
        {
            float angles[3];
            calculateAngles(3, 4, 5, angles);  // Right triangle (3-4-5)
            Assert::AreEqual(36.87f, angles[0], 0.1f);  // Angle 1
            Assert::AreEqual(53.13f, angles[1], 0.1f);  // Angle 2
            Assert::AreEqual(90.0f, angles[2], 0.1f);   // Angle 3 should be 90°
        }

        // Verifies that degenerate triangles (not a valid triangle) return false.
        TEST_METHOD(isTriangle_Degenerate_Triangle_Return_False)
        {
            bool* result = isTriangle(1, 2, 3);  // Degenerate triangle, sides don't form a valid triangle
            Assert::IsFalse(result);  // Expecting false
        }

	};
}
