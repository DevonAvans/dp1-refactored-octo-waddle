#include "pch.h"
#include "CppUnitTest.h"
#include "Util.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test::util
{
	TEST_CLASS(TestSafeStoi)
	{
	public:
		TEST_METHOD(test_valid_integer_strings)
		{
			// Arrange
			const auto value = "123";
			const auto actual = 123;

			// Act
			const int expected = utils::safe_stoi(value);

			// Assert
			Assert::AreEqual(expected, actual, L"Conversion of '123' failed");
		}

		TEST_METHOD(test_negative_integer_strings)
		{
			// Arrange
			const auto value = "-456";
			const auto actual = -456;

			// Act
			const int expected = utils::safe_stoi(value);

			// Assert
			Assert::AreEqual(expected, actual, L"Conversion of '-456' failed");
		}

		TEST_METHOD(test_invalid_integer_strings)
		{
			// Arrange
			const auto value = "abc";

			// Act and Assert
			Assert::ExpectException<std::exception>([]
			{
				utils::safe_stoi("value");
			});
		}
	};
}
