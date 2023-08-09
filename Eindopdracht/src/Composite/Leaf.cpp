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
}


int Leaf::get_row() const
{
	return attributes_.row;
}

int Leaf::get_col() const
{
	return attributes_.col;
}

void Leaf::set_state(CellState* state)
{
	current_state_ = state;
}
