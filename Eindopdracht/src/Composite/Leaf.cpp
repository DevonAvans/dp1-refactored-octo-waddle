#include "Composite/Leaf.hpp"

#include "State/CellState.hpp"
#include "State/EmptyState.hpp"
#include "State/FinalState.hpp"
#include "Visitor/Visitor.hpp"

Leaf::Leaf(CellAttributes attributes, const int initial_value) :
	current_state_{nullptr},
	attributes_{attributes},
	value_{initial_value}
{
	if (initial_value != 0)
	{
		set_state(new FinalState());
	}
	else
	{
		set_state(new EmptyState());
	}
}

void Leaf::accept(Visitor* visitor)
{
	visitor->visit_leaf(this);
}

int Leaf::get_value() const
{
	return value_;
}

void Leaf::set_value(const int value)
{
	current_state_->set_value(*this, value);
	candidates_.clear();
}

CellAttributes Leaf::get_attributes() const
{
	return attributes_;
}

void Leaf::set_state(CellState* state)
{
	current_state_ = state;
}

std::vector<int> Leaf::get_candidates() const
{
	return candidates_;
}

void Leaf::add_candidates(const int candidate)
{
	const auto existing_candidate = std::ranges::find(candidates_, candidate);

	if (existing_candidate == candidates_.end())
	{
		candidates_.emplace_back(candidate);
	}
	else
	{
		candidates_.erase(existing_candidate);
	}
}

void Leaf::remove_candidates(const int canidate)
{
	std::erase(candidates_, canidate);
}
