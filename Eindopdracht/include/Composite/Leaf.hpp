#pragma once
#include "Component.hpp"

class Leaf final : public Component
{
public:
	explicit Leaf(int row, int col, int value);

	void display() const override;
	void accept(Visitor* visitor) override;

	[[nodiscard]] int get_value() const override;
	[[nodiscard]] int get_row() const;
	[[nodiscard]] int get_col() const;

private:
	int row_;
	int col_;
	int value_;
};
