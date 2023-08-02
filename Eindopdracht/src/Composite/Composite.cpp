#include "Composite/Composite.hpp"

void Composite::add_child(const std::shared_ptr<Component>& component)
{
	children_.emplace_back(component);
}

int Composite::get_value() const
{
	return 0;
}

void Composite::display() const
{
}
