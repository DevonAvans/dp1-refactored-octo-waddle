#pragma once
#include "Visitor.hpp"

class ValidationVisitor : public Visitor
{
public:
	explicit ValidationVisitor();

	void visit_leaf(Leaf* leaf) override;
	void visit_composite(Composite* composite) override;

private:
	bool valid_;

	bool validate_row();
	bool validate_col();
	bool validate_section();
};
