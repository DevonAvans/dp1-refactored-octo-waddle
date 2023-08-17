#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(Test)
	{
	public:
		TEST_METHOD(test_method1)
		{
			// Arrange
			const int a = 1;
			const int b = 2;

			// Act
			const int result = a + b;

			// Assert
			Assert::AreEqual(result, 3, L"Sum of a and b should be 3");
		}
	};
}
