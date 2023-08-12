#pragma once

class Leaf;

class CellState
{
public:
	virtual void set_value(Leaf& cell, int value) = 0;
	virtual void set_valid(Leaf& cell, bool value) = 0;
protected:
	void set_cell_value(Leaf& cell, const int value);

	void set_cell_valid(Leaf& cell, const bool valid);
};
