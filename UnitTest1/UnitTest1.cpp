#include "pch.h"
#include "CppUnitTest.h"
#include "..//AP 12.5/AP 12.5.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::IsTrue(isRightTriangle(3, 4, 5));
		}
	};
}
