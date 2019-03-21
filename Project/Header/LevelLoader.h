#pragma once
#define Level_Loader
#ifdef Level_Loader

#include <SFML/System/Vector2.hpp>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include "..\yaml-cpp\yaml.h"

struct PlatformData
{
	std::string m_type;
	sf::Vector2f m_position;
	sf::Vector2f m_size;
};

struct LevelData
{
	std::vector<PlatformData> m_platform;
};


class LevelLoader
{
public:

	LevelLoader();

	static bool load(int nr, LevelData& level);
};

#endif // !Level_Loader