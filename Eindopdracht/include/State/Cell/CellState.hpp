#pragma once

class Leaf;

class CellState
{
public:
	virtual ~CellState() = default;
	virtual void set_value(Leaf& cell, int value) = 0;
	virtual void set_valid(Leaf& cell, bool value) = 0;
protected:
	static void set_cell_value(Leaf& cell, int value);
	static void set_cell_valid(Leaf& cell, bool valid);
};
