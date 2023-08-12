#pragma once
#include <memory>
#include <vector>

#include "CellAttributes.hpp"
#include "Component.hpp"
#include "State/Cell/CellState.hpp"

class Leaf final : public Component
{
public:
	explicit Leaf(CellAttributes attributes, int initial_value, std::unique_ptr<CellState> state);

	void accept(Visitor* visitor) override;

	void set_state(std::unique_ptr<CellState> state);

	[[nodiscard]] CellAttributes get_attributes() const;

	void set_value(int value);
	[[nodiscard]] int get_value() const;

	void add_candidates(int candidate);
	void remove_candidates(int canidate);
	[[nodiscard]] std::vector<int> get_candidates() const;

	[[nodiscard]] bool is_valid() const override;
	void set_valid(bool valid) override;

private:
	std::unique_ptr<CellState> current_state_;

	CellAttributes attributes_;
	int value_;
	std::vector<int> candidates_;

	friend class CellState;
};
