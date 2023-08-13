#include "Util.hpp"

#include <stdexcept>

namespace utils
{
	int safe_stoi(const std::string& str)
	{
		try
		{
			return std::stoi(str);
		}
		catch ([[maybe_unused]] const std::runtime_error& e)
		{
			throw std::runtime_error("Failed stoi");
		}
	}
}
