#include "pch.h"
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
		
		TEST_METHOD(TestMethod1)
		{

		}
	};
}
