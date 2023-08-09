#pragma once
#include "CellAttributes.hpp"
#include "Component.hpp"


class Configuration;
class CellState;

class Leaf final : public Component
{
public:
	explicit Leaf(CellAttributes attributes, int initial_value);

	void accept(Visitor* visitor) override;

	[[nodiscard]] int get_value() const override;
	void set_value(int value);
	[[nodiscard]] int get_row() const;
	[[nodiscard]] int get_col() const;
	[[nodiscard]] int get_section() const;

	void set_state(CellState* state);

private:
	CellState* current_state_;
	// const std::unique_ptr<Configuration>& config_;

	CellAttributes attributes_;
	int value_;

	friend CellState;
};
