#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test::CellState
{
	TEST_CLASS(CellState)
	{
	public:
		TEST_METHOD(change_tile_empty_state)
		{
			const auto inital_value = 0;
			const auto new_value = 5;
			const auto component = factory_->create({0, 0, 0, 9}, inital_value);
			const auto cell = dynamic_cast<Leaf*>(component.get());
			if (cell == nullptr) return;
			cell->set_value(new_value);
			Assert::AreEqual(cell->get_value(), new_value, L"Cell value shouldn't be changed. Expected value 0");
		}

		TEST_METHOD(change_tile_final_state)
		{
			const auto inital_value = 1;
			const auto new_value = 5;
			const auto component = factory_->create({0, 0, 0, 9}, inital_value);
			const auto cell = dynamic_cast<Leaf*>(component.get());
			if (cell == nullptr) return;
			cell->set_value(new_value);
			Assert::AreEqual(cell->get_value(), inital_value, L"Cell value shouldn't be changed. Expected value 5");
		}

	private:
		std::unique_ptr<CellFactory> factory_ = std::make_unique<CellFactory>();
	};
}
