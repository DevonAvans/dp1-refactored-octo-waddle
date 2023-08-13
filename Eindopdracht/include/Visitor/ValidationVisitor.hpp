#pragma once

#include <set>
#include <unordered_map>

#include "Visitor.hpp"

class ValidationVisitor : public Visitor
{
public:
	explicit ValidationVisitor(int size);

	void visit_leaf(Leaf* leaf) override;
	void visit_composite(Composite* composite) override;
	void reset();

private:
	int size_;
	bool valid_;

	std::vector<std::vector<Leaf*>> rows_;
	std::vector<std::vector<Leaf*>> cols_;
	std::vector<std::vector<Leaf*>> sections_;

	static void check_uniqueness_and_update_validity(const std::vector<Leaf*>& cells);
};
