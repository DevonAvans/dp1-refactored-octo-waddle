#pragma once
#include <memory>
#include <string>
#include <vector>

#include "SudokuBuilder.hpp"
#include "Factory/CellFactory.hpp"

class Component;
class Composite;

struct Offset
{
	int row, col;
};

class SamuraiBuilder final : public SudokuBuilder
{
public:
	SamuraiBuilder();
	std::shared_ptr<Component> get() override;

	void create_top_left(const std::string& data) const;
	void create_top_right(const std::string& data) const;
	void create_middle(const std::string& data);
	void create_bottom_left(const std::string& data) const;
	void create_bottom_right(const std::string& data) const;

private:
	std::unique_ptr<CellFactory> factory_;
	std::shared_ptr<Composite> value_;

	std::shared_ptr<Composite> top_left_;
	std::shared_ptr<Composite> top_right_;
	std::shared_ptr<Composite> bottom_right_;
	std::shared_ptr<Composite> bottom_left_;

	void ching_chong(std::vector<std::shared_ptr<Composite>>& sections, const std::string& data, Offset offset) const;
	void bind(const std::vector<std::shared_ptr<Composite>>& sections) const;
public:
	void build_size(int size) override
	{
	};

	void build_cell(const CellAttributes& attributes, int value) const override
	{
	}
};
