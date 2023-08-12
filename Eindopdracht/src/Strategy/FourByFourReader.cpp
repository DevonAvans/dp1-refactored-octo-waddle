#include "Strategy/FourByFourReader.hpp"

#include "Factory/SudokuFactory.hpp"

std::shared_ptr<Component> FourByFourReader::read(const std::string& path)
{
	factory_ = std::make_unique<SudokuFactory>();
	const auto str = read_file(path);

	return factory_->create(str);
}
