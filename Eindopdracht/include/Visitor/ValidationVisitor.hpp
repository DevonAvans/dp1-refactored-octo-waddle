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

	bool check_uniqueness(const int value, std::set<int>& set)
	{
		if (set.contains(value))
		{
			return false; // Value already exists in the set
		}
		set.insert(value);
		return true;
	}

	void CheckUniquenessAndUpdateValidity(std::vector<Leaf*>& cells)
	{
		std::unordered_map<int, int> valueCounts;

		for (Leaf* cell : cells)
		{
			int value = cell->get_value();
			valueCounts[value]++;
		}

		for (Leaf* cell : cells)
		{
			if (valueCounts[cell->get_value()] > 1)
			{
				cell->set_valid(false);
			}
		}
	}
};
