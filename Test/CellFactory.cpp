#include "pch.h"
#include "CppUnitTest.h"
#include "Composite/Leaf.hpp"
#include "State/Cell/EmptyState.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test::factory
{
	TEST_CLASS(CellFactoryClass)
	{
	public:
		TEST_METHOD(cell_factory_with_initial_value_0)
		{
			// Arrange
			const auto initial_value = 0;
			const auto attributes = CellAttributes{0, 0, 0};
			const auto cell = std::make_unique<Leaf>(attributes, initial_value, std::make_unique<EmptyState>());
			const auto value = 2;

			// Act
			const auto component = factory_->create(attributes, initial_value);
			const auto leaf = dynamic_cast<Leaf*>(component.get());
			if (leaf == nullptr) return;
			leaf->set_value(value);
			cell->set_value(value);

			// Assert
			Assert::AreEqual(cell->get_value(), leaf->get_value(), L"Message");
			Assert::AreEqual(std::empty(cell->get_candidates()), true, L"Message");
			Assert::AreEqual(std::empty(leaf->get_candidates()), true, L"Message");
		}

		TEST_METHOD(cell_factory_with_initial_value_2)
		{
			// Arrange
			const auto initial_value = 2;
			const auto attributes = CellAttributes{0, 0, 0};
			const auto cell = std::make_unique<Leaf>(attributes, initial_value, std::make_unique<EmptyState>());
			const auto value = 1;

			// Act
			const auto component = factory_->create(attributes, initial_value);
			const auto leaf = dynamic_cast<Leaf*>(component.get());
			if (leaf == nullptr) return;
			leaf->set_value(value);
			cell->set_value(value);

			// Assert
			Assert::AreEqual(cell->get_value(), leaf->get_value(), L"Message");
			Assert::AreEqual(std::empty(cell->get_candidates()), true, L"Message");
			Assert::AreEqual(std::empty(leaf->get_candidates()), true, L"Message");
		}

	private:
		std::unique_ptr<CellFactory> factory_ = std::make_unique<CellFactory>();
	};
}
