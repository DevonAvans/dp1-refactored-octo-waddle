#pragma once

#include "Composite/Composite.hpp"
#include "Composite/Leaf.hpp"

class Visitor
{
public:
	virtual ~Visitor() = default;
	virtual void visit_leaf(Leaf* leaf) = 0;
	virtual void visit_composite(Composite* composite) = 0;
};
