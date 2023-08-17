#include "pch.h"
#include "CppUnitTest.h"
#include "Util.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(Test)
	{
	public:
		TEST_METHOD(test_method1)
		{
			// Arrange
			int a = 1;
			int b = 2;

			// Act
			int result = a + b;

			// Assert
			Assert::AreEqual(result, 3, L"Sum of a and b should be 3");
		}
	};

	TEST_CLASS(TestSafeStoi)
	{
	public:
		TEST_METHOD(test_valid_integer_strings)
		{
			const int result = utils::safe_stoi("123");
			Assert::AreEqual(result, 123, L"Conversion of '123' failed");
		}

		TEST_METHOD(test_negative_integer_strings)
		{
			const int result = utils::safe_stoi("-456");
			Assert::AreEqual(result, -456, L"Conversion of '-456' failed");
		}

		TEST_METHOD(test_invalid_integer_strings)
		{
			Assert::ExpectException<std::exception>([]()
			{
				utils::safe_stoi("abc");
			});
		}
	};
}
