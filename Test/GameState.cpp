#include "pch.h"
#include "CppUnitTest.h"

#include "State/Game/DefinitiveGameState.hpp"
#include "State/Game/HelperGameState.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test::game_state
{
	TEST_CLASS(GameState)
	{
	public:
		TEST_METHOD(change_value_definitive_game_state)
		{
			// Arrange
			const auto actual = 3;
			const auto game = std::make_unique<Game>(path_, std::make_unique<DefinitiveGameState>());
			game->set_searcher_target(0, 0);
			const auto cell = game->get_searcher_target();

			// Act
			game->set_cell_value(*cell, actual);

			// Assert
			Assert::AreEqual(cell->get_value(), actual,
			                 L"Cell value is changed. Cell value is 3, candidates are empty");
			Assert::AreEqual(std::empty(cell->get_candidates()), true,
			                 L"Candidates are empty");
		}

		TEST_METHOD(change_value_helper_game_state)
		{
			// Arrange
			const auto candidate1 = 1;
			const auto candidate2 = 3;
			const auto game = std::make_unique<Game>(path_, std::make_unique<HelperGameState>());
			game->set_searcher_target(0, 0);
			const auto cell = game->get_searcher_target();

			// Act
			game->set_cell_value(*cell, candidate1);
			game->set_cell_value(*cell, candidate2);

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
	};
}
