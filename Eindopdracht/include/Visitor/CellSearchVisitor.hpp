#pragma once
#include "Visitor.hpp"

class CellSearchVisitor : public Visitor
{
public:
	explicit CellSearchVisitor(const int row, const int col);
	void visit_leaf(Leaf* leaf) override;
	void visit_composite(Composite* composite) override;
	[[nodiscard]] Leaf* get_cell() const;
private:
	int target_row_;
	int target_col_;
	Leaf* cell_;
};
