#pragma once

/// <summary>
/// @SplashScreen splash screen to be played before the title screen 
/// @author Jamie Murphy and Sean Regan
/// @Version 0.1
/// @brief Opening screen to display company logo
/// </summary>

#include "Game.h"
#include <SFML\Graphics.hpp>

class Game;

class SplashScreen
{
public:
	SplashScreen(Game &game);
	~SplashScreen();
	void update(sf::Time deltaTime);
	void render(sf::RenderWindow & window);
	void setStateBack();

private:

	Game *m_game;

	int m_currentSelect = 0;
	sf::Time m_cumulativeTime;
	sf::Font myFont;
	sf::Font myFont2;
	sf::Text text;
	sf::Text text2;
	

};
