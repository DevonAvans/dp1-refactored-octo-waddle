#pragma once
#include "CellAttributes.hpp"
#include "Component.hpp"

class CellState;

class Leaf final : public Component
{
public:
	explicit Leaf(CellAttributes attributes, int initial_value);

	void accept(Visitor* visitor) override;

	[[nodiscard]] int get_value() const override;
	void set_value(int value);
	[[nodiscard]] CellAttributes get_attributes() const;

	void set_state(CellState* state);

private:
	CellState* current_state_;

	CellAttributes attributes_;
	int value_;

	friend CellState;
};
