#include "Composite/Leaf.hpp"

#include "State/CellState.hpp"
#include "State/EmptyState.hpp"
#include "State/FinalState.hpp"
#include "Visitor/Visitor.hpp"

Leaf::Leaf(const int row, const int col, const int initial_value) : current_state_{nullptr}, row_{row}, col_{col},
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

void Leaf::display() const
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
	//if (current_state_->can_set_value())
	//{
	current_state_->set_value(*this, value);
	//}
}

void Leaf::set_raw_value(int value)
{
	value_ = value;
}

int Leaf::get_row() const
{
	return row_;
}

int Leaf::get_col() const
{
	return col_;
}

void Leaf::set_state(CellState* state)
{
	current_state_ = state;
}
