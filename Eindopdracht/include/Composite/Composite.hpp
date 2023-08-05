#pragma once
#include <memory>
#include <vector>

#include "Component.hpp"

class Composite : public Component
{
public:
	void add_child(const std::shared_ptr<Component>& component);
	//size_t get_size() const;
	[[nodiscard]] int get_value() const override;
	void display() const override;
	void accept(Visitor* visitor) override;
	[[nodiscard]] std::vector<std::shared_ptr<Component>> get_children() const;

private:
	std::vector<std::shared_ptr<Component>> children_;
};
