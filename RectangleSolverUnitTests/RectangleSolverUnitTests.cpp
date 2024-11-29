#include "pch.h"
#include "CppUnitTest.h"

extern "C" bool checkIfRectangular(POINT points[4]);
extern "C" void swapTwoPoints(POINT points[4], int point1, int point2);
extern "C" double getRectanglePerimeter(POINT points[4]);
extern "C" double getRectangleArea(POINT points[4]);
extern "C" double* getTwoRectangleEdges(POINT points[4]);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleSolverUnitTests
{
	TEST_CLASS(RectangleSolverUnitTests)
	{
	public:
		
        // Ensures that when all points are identical, the rectangle check fails.
        TEST_METHOD(CheckIfRectangular_4_Identical_Points_Return_False)
        {
            POINT points[4] = { {0, 0}, {0, 0}, {0, 0}, {0, 0} };  // All points are identical
            bool result = checkIfRectangular(points);
            Assert::IsFalse(result);  // Expecting false because a rectangle can't have all identical points
        }

        // Tests a valid ordered rectangle.
        TEST_METHOD(CheckIfRectangular_Valid_Ordered_Points_Return_True)
        {
            POINT points[4] = { {0, 0}, {4, 0}, {4, 3}, {0, 3} };  // Ordered points forming a rectangle
            bool result = checkIfRectangular(points);
            Assert::IsTrue(result);  // Expecting true since it's a valid rectangle
        }

        // Tests an unordered set of valid points that still form a rectangle.
        TEST_METHOD(CheckIfRectangular_Valid_UnOrdered_Points_Return_True)
        {
            POINT points[4] = { {4, 0}, {0, 3}, {0, 0}, {4, 3} };  // Unordered points that form a valid rectangle
            bool result = checkIfRectangular(points);
            Assert::IsTrue(result);  // Expecting true because they form a valid rectangle
        }

        // Tests random points that do not form a rectangle, expecting the function to return false.
        TEST_METHOD(CheckIfRectangular_Invalid_Points_Return_False)
        {
            POINT points[4] = { {0, 0}, {1, 2}, {3, 5}, {4, 7} };  // Random points that don't form a rectangle
            bool result = checkIfRectangular(points);
            Assert::IsFalse(result);  // Expecting false because these points do not form a valid rectangle
        }

        // Calculates and checks the perimeter of a known rectangle.
        TEST_METHOD(GetRectanglePerimeter_Valid_Rectangle)
        {
            POINT points[4] = { {0, 0}, {4, 0}, {4, 3}, {0, 3} };  // Rectangle with perimeter 14
            double result = getRectanglePerimeter(points);
            Assert::AreEqual(14.0, result, 0.01);  // Expecting perimeter of 14 with small tolerance
        }

        // Calculates and checks the area of a known rectangle.
        TEST_METHOD(GetRectangleArea_Valid_Rectangle)
        {
            POINT points[4] = { {0, 0}, {4, 0}, {4, 3}, {0, 3} };  // Rectangle with area 12
            double result = getRectangleArea(points);
            Assert::AreEqual(12.0, result, 0.01);  // Expecting area of 12 with tolerance for floating-point precision
        }

        // Extracts two edges from a rectangle and checks their lengths.
        TEST_METHOD(GetTwoRectangleEdges_Valid_Rectangle)
        {
            POINT points[4] = { {0, 0}, {4, 0}, {4, 3}, {0, 3} };  // Rectangle with edges 4 and 3
            double* edges = getTwoRectangleEdges(points);
            Assert::AreEqual(4.0, edges[0], 0.01);  // First edge should be 4
            Assert::AreEqual(3.0, edges[1], 0.01);  // Second edge should be 3
        }
	};
}
