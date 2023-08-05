#pragma once
#include "Component.hpp"

class CellState;

class Leaf final : public Component
{
public:
	explicit Leaf(int row, int col, int initial_value);

	void display() const override;
	void accept(Visitor* visitor) override;

	[[nodiscard]] int get_value() const override;
	void set_value(int value);
	void set_raw_value(int value);
	[[nodiscard]] int get_row() const;
	[[nodiscard]] int get_col() const;

	void set_state(CellState* state);

private:
	CellState* current_state_;

	int row_;
	int col_;
	int value_;

	friend CellState;
};
