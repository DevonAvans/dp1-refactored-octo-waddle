#pragma once

class Component
{
public:
	virtual int get_value() const = 0;
	virtual void display() const = 0;
};
