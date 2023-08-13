#include "Factory/SudokuFactory.hpp"

#include "Strategy/FourByFourReader.hpp"
#include "Strategy/JigsawReader.hpp"
#include "Strategy/NineByNineReader.hpp"
#include "Strategy/SamuraiReader.hpp"
#include "Strategy/SixBySixReader.hpp"

SudokuFactory::SudokuFactory()
{
	dictionairy_[".4x4"] = std::make_shared<FourByFourReader>();
	dictionairy_[".6x6"] = std::make_shared<SixBySixReader>();
	dictionairy_[".9x9"] = std::make_shared<NineByNineReader>();
	dictionairy_[".samurai"] = std::make_shared<SamuraiReader>();
	dictionairy_[".jigsaw"] = std::make_shared<JigsawReader>();
}

std::shared_ptr<Component> SudokuFactory::create(const std::string& path)
{
	const std::string extension = get_extension(path);

	if (dictionairy_.contains(extension))
	{
		return dictionairy_[extension]->read(path);
	}

	return nullptr;
}

std::string SudokuFactory::get_extension(const std::string& path)
{
	const size_t last_dot_pos = path.find_last_of('.');
	if (last_dot_pos != std::string::npos)
	{
		return path.substr(last_dot_pos);
	}
	return "";
}
