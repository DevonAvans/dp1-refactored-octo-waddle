#pragma once
#include "Visitor.hpp"

class SudokuVisitor : public Visitor
{
public:
	void visit_leaf(Leaf* leaf) override;
	void visit_composite(Composite* composite) override;
};
