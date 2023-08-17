#include "Composite/Leaf.hpp"

#include "Visitor/Visitor.hpp"

Leaf::Leaf(CellAttributes attributes, const int initial_value, std::unique_ptr<CellState> state) :
	current_state_{std::move(state)},
	attributes_{attributes},
	value_{initial_value}
{
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
	if (value > attributes_.max) return;
	current_state_->set_value(*this, value);
	valid_ = true;
	candidates_.clear();
}

CellAttributes Leaf::get_attributes() const
{
	return attributes_;
}

void Leaf::set_state(std::unique_ptr<CellState> state)
{
	current_state_ = std::move(state);
}

std::vector<int> Leaf::get_candidates() const
{
	return candidates_;
}

void Leaf::add_candidates(const int candidate)
{
	const auto existing_candidate = std::ranges::find(candidates_, candidate);
	if (candidate == 0 || candidate > attributes_.max) return;
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

bool Leaf::is_valid() const
{
	return value_ != 0 && valid_;
}

void Leaf::set_valid(const bool valid)
{
	current_state_->set_valid(*this, valid);
}
