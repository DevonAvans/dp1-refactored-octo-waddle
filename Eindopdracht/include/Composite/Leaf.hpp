#pragma once
#include <vector>

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

	[[nodiscard]] std::vector<int> get_candidates() const;
	void add_candidates(int canidate);
	void remove_candidates(int canidate);

private:
	CellState* current_state_;

	CellAttributes attributes_;
	int value_;
	std::vector<int> candidates_;

	friend CellState;
};
