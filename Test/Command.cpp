#include "pch.h"
#include "CppUnitTest.h"
#include "State/Game/DefinitiveGameState.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test::command
{
	TEST_CLASS(CheckCommand)
	{
	public:
		TEST_METHOD(sudoku4x4_is_not_solved)
		{
			// Arrange
			// Default game config

			// Act
			game_->execute_command(key::Check);

			// Assert
			Assert::AreEqual(game_->get_sudoku()->is_valid(), false, L"Sudoku is not valid");
		}

		TEST_METHOD(sudoku4x4_is_solved)
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

	TEST_CLASS(GameStateCommands)
	{
	public:
		TEST_METHOD(definitive_command)
		{
			// Arrange
			const auto actual = 3;
			// Default game config
			game_->set_searcher_target(0, 0);
			const auto cell = game_->get_searcher_target();

			// Act
			game_->execute_command(key::Definitive);
			game_->set_cell_value(*cell, actual);

			// Assert
			Assert::AreEqual(cell->get_value(), actual, L"Value of cell should be changed");
			Assert::AreEqual(std::empty(cell->get_candidates()), true, L"Candidates array should be empty");
		}

		TEST_METHOD(helper_command)
		{
			// Arrange
			const auto candidate1 = 1;
			const auto candidate2 = 3;
			// Default game config
			game_->set_searcher_target(0, 0);
			const auto cell = game_->get_searcher_target();

			// Act
			game_->execute_command(key::Helper);
			game_->set_cell_value(*cell, candidate1);
			game_->set_cell_value(*cell, candidate2);

			const auto& candidates = cell->get_candidates();
			const bool contains_value1 = std::ranges::find(candidates, candidate1) != candidates.end();
			const bool contains_value3 = std::ranges::find(candidates, candidate2) != candidates.end();

			// Assert
			Assert::AreEqual(cell->get_value(), 0, L"Cell value shouldn't be changed. Expected value 0");
			Assert::IsTrue(contains_value1, L"Candidates should contain the value 1");
			Assert::IsTrue(contains_value3, L"Candidates should contain the value 3");
		}

	private:
		const char* path_ = "resources/puzzle.4x4";
		std::unique_ptr<Game> game_ = std::make_unique<Game>(path_, std::make_unique<DefinitiveGameState>());
	};
}
