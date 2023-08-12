#pragma once

class Visitor;

class Component
{
public:
	virtual ~Component() = default;
	[[nodiscard]] virtual int get_value() const = 0;
	virtual void accept(Visitor* visitor) = 0;

	virtual void set_valid(const bool valid) { valid_ = valid; }
	[[nodiscard]] virtual bool is_valid() const { return valid_; }

protected:
	bool valid_{true};
};
