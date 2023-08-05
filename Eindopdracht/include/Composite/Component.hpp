#pragma once
#include <memory>

class Visitor;

class Component
{
public:
	virtual ~Component() = default;
	[[nodiscard]] virtual int get_value() const = 0;
	virtual void display() const = 0;
	virtual void accept(Visitor* visitor) = 0;
};
