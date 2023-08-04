#include "Composite/Composite.hpp"
#include "Visitor/Visitor.hpp"

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

void Composite::accept(Visitor* visitor)
{
	visitor->visit_composite(this);
}

std::vector<std::shared_ptr<Component>> Composite::get_children() const
{
	return children_;
}
