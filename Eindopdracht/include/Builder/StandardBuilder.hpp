#pragma once
#include <vector>

#include "CellAttributes.hpp"
#include "SudokuBuilder.hpp"
#include "Composite/Composite.hpp"

#include "Factory/CellFactory.hpp"

class StandardBuilder : public SudokuBuilder
{
public:
	void build_size(int size) override;
	void build_cell(const CellAttributes& attributes, int value) const override;
	std::shared_ptr<Component> get() override;

private:
	std::unique_ptr<CellFactory> factory_;
	std::shared_ptr<Composite> sudoku_;
	std::vector<std::shared_ptr<Composite>> sections_;
};
