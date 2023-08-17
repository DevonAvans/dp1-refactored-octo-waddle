#include "pch.h"
#include "CppUnitTest.h"
#include "State/Game/DefinitiveGameState.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test::command
{
	TEST_CLASS(CheckCommand)
	{
	public:
		TEST_METHOD(sudoku_is_not_solved)
		{
			// Arrange
			// Default game config

			// Act
			game_->execute_command(key::Check);

			// Assert
			Assert::AreEqual(game_->get_sudoku()->is_valid(), false, L"Sudoku is not valid");
		}

		TEST_METHOD(sudoku_is_solved)
		{
			// Arrange
			// row 0
			game_->set_searcher_target(0, 0);
			game_->set_cell_value(*game_->get_searcher_target(), 2);

			game_->set_searcher_target(0, 3);
			game_->set_cell_value(*game_->get_searcher_target(), 1);

			// row 1
			game_->set_searcher_target(1, 1);
			game_->set_cell_value(*game_->get_searcher_target(), 1);

			game_->set_searcher_target(1, 2);
			game_->set_cell_value(*game_->get_searcher_target(), 3);


			// row 2
			game_->set_searcher_target(2, 1);
			game_->set_cell_value(*game_->get_searcher_target(), 4);

			game_->set_searcher_target(2, 2);
			game_->set_cell_value(*game_->get_searcher_target(), 2);

			// row 3
			game_->set_searcher_target(3, 0);
			game_->set_cell_value(*game_->get_searcher_target(), 3);

			game_->set_searcher_target(3, 3);
			game_->set_cell_value(*game_->get_searcher_target(), 4);

			// Act
			game_->execute_command(key::Check);

			// Assert
			Assert::AreEqual(game_->get_sudoku()->is_valid(), true, L"Sudoku is solved");
		}

	private:
		const char* path_ = "resources/puzzle.4x4";
		std::unique_ptr<Game> game_ = std::make_unique<Game>(path_, std::make_unique<DefinitiveGameState>());
	};

	TEST_CLASS(LoadPuzzleCommand)
	{
	public:
		TEST_METHOD(load_puzzle)
		{
			// Arrange
			// Default game config
			const auto expected_value = 4;

			// Act
			game_->execute_command(key::LoadPuzzle);
			game_->set_searcher_target(0, 0);
			const auto att = game_->get_searcher_target()->get_attributes();

			// Assert
			Assert::AreEqual(att.max, expected_value, L"The sudoku size is now 4");
		}

	private:
		const char* path_ = "resources/puzzle.jigsaw";
		std::unique_ptr<Game> game_ = std::make_unique<Game>(path_, std::make_unique<DefinitiveGameState>());
	};
}
