#pragma once

/// <summary>
/// @Gameplay screen to be played before the Main Menu screen 
/// @author Jamie Murphy and Sean Regan
/// @Version 0.1
/// @brief Opening screen to display company logo
/// </summary>

#include "Game.h"
#include <SFML\Graphics.hpp>

class Platform;
class Player;
class Game;

class GameplayScreen
{
public:
	GameplayScreen(Game &game);
	~GameplayScreen();
	void update(sf::Time deltaTime);
	void render(sf::RenderWindow & window);

	void GeneratePlatform();
	LevelData m_level;
	std::unique_ptr<Platform>m_ground;
	std::vector<Platform>m_platform;
	std::unique_ptr<Player>m_player;


private:

	Game *m_game;

	int m_currentSelect = 0;
	sf::Time m_cumulativeTime;
	sf::Font myFont;
	sf::Font myFont2;
	sf::Text text;
	sf::Text text2;


};
