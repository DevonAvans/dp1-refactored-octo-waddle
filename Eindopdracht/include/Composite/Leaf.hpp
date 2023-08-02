#pragma once
#include "Component.hpp"

class Leaf final : public Component
{
public:
	explicit Leaf(int value);

	[[nodiscard]] int get_value() const override;
	void display() const override;

private:
	int value_;
};
