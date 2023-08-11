#pragma once
#include "CellSearchVisitor.hpp"

class SamuraiCellSearcher : public CellSearchVisitor
{
public:
	void visit_leaf(Leaf* leaf) override
	{
	}

	void visit_composite(Composite* composite) override;
	~SamuraiCellSearcher() override;

private:
	std::vector<Leaf*> collection_;
};
