#pragma once
#include <memory>
#include <vector>

#include "Component.hpp"

class Composite final : public Component
{
public:
	void add_child(const std::shared_ptr<Component>& component);
	void accept(Visitor* visitor) override;
	[[nodiscard]] std::vector<std::shared_ptr<Component>> get_children() const;
	[[nodiscard]] bool is_valid() const override;

private:
	std::vector<std::shared_ptr<Component>> children_;
};
