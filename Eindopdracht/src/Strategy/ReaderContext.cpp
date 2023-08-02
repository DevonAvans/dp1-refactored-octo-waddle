#include "Strategy/ReaderContext.hpp"

#include "Strategy/FourByFourReader.hpp"
#include "Strategy/JigsawReader.hpp"
#include "Strategy/NineByNineReader.hpp"
#include "Strategy/SamuraiReader.hpp"
#include "Strategy/SixBySixReader.hpp"

ReaderContext::ReaderContext()
{
	dictionairy_[".4x4"] = std::make_shared<FourByFourReader>();
	dictionairy_[".6x6"] = std::make_shared<SixBySixReader>();
	dictionairy_[".9x9"] = std::make_shared<NineByNineReader>();
	dictionairy_[".samurai"] = std::make_shared<SamuraiReader>();
	dictionairy_[".jigsaw"] = std::make_shared<JigsawReader>();
}

ReaderContext::~ReaderContext()
{
}

void ReaderContext::set_strategy(std::shared_ptr<SudokuReader> reader)
{
}

std::shared_ptr<Component> ReaderContext::read(const std::string& path)
{
	const std::string extension = get_extension(path);

	if (dictionairy_.contains(extension))
	{
		return dictionairy_[extension]->read(path);
	}

	return nullptr;
}

std::string ReaderContext::get_extension(const std::string& path)
{
	const size_t last_dot_pos = path.find_last_of('.');
	if (last_dot_pos != std::string::npos)
	{
		return path.substr(last_dot_pos);
	}
	return "";
}
