#include "../Header/LevelLoader.h"
#include <time.h>


void operator >> (const YAML::Node & platformNode, PlatformData& platform)
{
	platform.m_type = platformNode["type"].as<std::string>();
	platform.m_position.x = platformNode["position"]["x"].as<float>();
	platform.m_position.y = platformNode["position"]["y"].as<float>();
	platform.m_size.x = platformNode["size"]["w"].as<float>();
	platform.m_size.y = platformNode["size"]["h"].as<float>();
}

void operator >> (const YAML::Node& nodeData, LevelData &level)
{
	const YAML::Node& platformNode = nodeData["platforms"].as<YAML::Node>();//loads nodes from yaml file
	for (unsigned i = 0; i < platformNode.size(); ++i)
	{
		PlatformData platform;
		platformNode[i] >> platform;
		level.m_platform.push_back(platform);

	}
}

LevelLoader::LevelLoader()
{

}


bool LevelLoader::load(int nr, LevelData &level)
{
	std::stringstream ss;
	ss << "./Level/level";//load form this file
	ss << nr;
	ss << ".yaml";

	try
	{
		YAML::Node baseNode = YAML::LoadFile(ss.str());
		if (baseNode.IsNull())
		{
			std::string message("file: " + ss.str() + " not found");

			throw std::exception(message.c_str());
		}
		baseNode >> level;
	}
	catch (YAML::ParserException& e)
	{
		std::cout << e.what() << "\n";
		return false;
	}

	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
		return false;
	}
	return true;
}
