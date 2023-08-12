#include "Composite/Composite.hpp"

#include <algorithm>

#include "Visitor/Visitor.hpp"


void Composite::add_child(const std::shared_ptr<Component>& component)
{
	children_.emplace_back(component);
}

void Composite::accept(Visitor* visitor)
{
	visitor->visit_composite(this);
}

std::vector<std::shared_ptr<Component>> Composite::get_children() const
{
	return children_;
}

bool Composite::is_valid() const
{
	return std::ranges::all_of(children_, [](const auto& child)
	{
		return child->is_valid();
	});
}
