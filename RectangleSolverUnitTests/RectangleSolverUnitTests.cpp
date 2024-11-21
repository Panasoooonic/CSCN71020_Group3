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
		
		// Test Case 1 - Input 4 identical points to checkIfRectangular()
		TEST_METHOD(CheckIfRectangular_4_Identical_Points_Return_False)
		{
		}

		// Test Case 2 - Input 4 valid points in order to checkIfRectangular()
		TEST_METHOD(CheckIfRectangular_Valid_Ordered_Points_Return_True)
		{
		}

		// Test Case 3 - Input 4 valid points not in order to checkIfRectangular()
		TEST_METHOD(CheckIfRectangular_Valid_UnOrdered_Points_Return_True)
		{
		}

		// Test Case 4 - Input 4 invalid points to checkIfRectangular()
		TEST_METHOD(CheckIfRectangular_Invalid_Points_Return_False)
		{
		}
	};
}
