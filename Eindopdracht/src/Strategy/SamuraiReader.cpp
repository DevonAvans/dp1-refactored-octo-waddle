#include "Strategy/SamuraiReader.hpp"

std::shared_ptr<Component> SamuraiReader::read(const std::string& path)
{
	const auto str = read_file(path);
	return nullptr;
}
