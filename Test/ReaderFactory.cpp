#include "pch.h"
#include "CppUnitTest.h"
#include "Factory/SudokuFactory.hpp"
#include "Strategy/FourByFourReader.hpp"
#include "Strategy/JigsawReader.hpp"
#include "Strategy/SamuraiReader.hpp"
#include "Strategy/SixBySixReader.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test::factory
{
	TEST_CLASS(ReaderFactory)
	{
	public:
		TEST_METHOD(four_by_four)
		{
			// Arrange
			const auto actual = 4;
			const auto path = "resources/puzzle.4x4";
			const auto four_reader = std::make_shared<FourByFourReader>();

			// Act
			const auto reader = factory_->create(path);

			// Assert
			Assert::AreEqual(reader->get_size(), actual, L"Reader is 4");
			Assert::AreEqual(four_reader->get_size(), actual, L"Reader size is 4");
		}

		TEST_METHOD(jigsaw)
		{
			// Arrange
			const auto actual = 9;
			const auto path = "resources/puzzle.jigsaw";
			const auto jigsaw_reader = std::make_shared<JigsawReader>();

			// Act
			const auto reader = factory_->create(path);

			// Assert
			Assert::AreEqual(reader->get_size(), actual, L"Reader is jigsaw");
			Assert::AreEqual(jigsaw_reader->get_size(), actual, L"Reader size is jigsaw");
		}

		TEST_METHOD(nine_by_nine)
		{
			// Arrange
			const auto actual = 9;
			const auto path = "resources/puzzle.9x9";
			const auto nine_reader = std::make_shared<JigsawReader>();

			// Act
			const auto reader = factory_->create(path);

			// Assert
			Assert::AreEqual(reader->get_size(), actual, L"Reader is 9");
			Assert::AreEqual(nine_reader->get_size(), actual, L"Reader size is 9");
		}

		TEST_METHOD(samurai)
		{
			// Arrange
			const auto actual = 21;
			const auto path = "resources/puzzle.samurai";
			const auto nine_reader = std::make_shared<SamuraiReader>();

			// Act
			const auto reader = factory_->create(path);

			// Assert
			Assert::AreEqual(reader->get_size(), actual, L"Reader is samurai");
			Assert::AreEqual(nine_reader->get_size(), actual, L"Reader size is samurai");
		}

		TEST_METHOD(six_by_six)
		{
			// Arrange
			const auto actual = 6;
			const auto path = "resources/puzzle.6x6";
			const auto nine_reader = std::make_shared<SixBySixReader>();

			// Act
			const auto reader = factory_->create(path);

			// Assert
			Assert::AreEqual(reader->get_size(), actual, L"Reader is 6");
			Assert::AreEqual(nine_reader->get_size(), actual, L"Reader size is 6");
		}

	private:
		std::unique_ptr<SudokuFactory> factory_ = std::make_unique<SudokuFactory>();
	};
}
