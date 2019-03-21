#pragma once

/// <summary>
/// @Titlescreen Title screen to be played before the main menu
/// @author Jamie Murphy and Sean Regan
/// @Version 0.1
/// @brief Opening screen to display company logo
/// </summary>

#include "../Header/Game.h"
#include "../Header/KeyHandler.h"
#include <SFML\Graphics.hpp>

class Game;

class Titlescreen
{
public:
	Titlescreen(Game &game);
	~Titlescreen();
	void update(sf::Time deltaTime);
	void render(sf::RenderWindow & window);
	void setStateBack();

private:

	Game *m_game;

	int m_currentSelect = 0;
	int alpha = 255;
	bool conToMenu;
	sf::Time m_cumulativeTime;
	sf::Font myFont;
	sf::Font myFont2;
	sf::Text text[5];
	KeyHandler keys;

};
