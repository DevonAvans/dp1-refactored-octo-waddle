#include "Factory/CellFactory.hpp"

#include "Composite/Leaf.hpp"
#include "State/Cell/EmptyState.hpp"
#include "State/Cell/FinalState.hpp"

std::shared_ptr<Component> CellFactory::create(const CellAttributes& attributes, const int initial_value) const
{
	if (initial_value == 0)
	{
		return std::make_shared<Leaf>(attributes, initial_value, std::make_unique<EmptyState>());
	}
	return std::make_shared<Leaf>(attributes, initial_value, std::make_unique<FinalState>());
}
