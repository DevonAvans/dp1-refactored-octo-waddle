#pragma once

class Configuration
{
public:
	explicit Configuration(const int size) : size_{size}
	{
	}

	[[no_discard]] int get_size() const
	{
		return size_;
	}

private:
	int size_;
};
