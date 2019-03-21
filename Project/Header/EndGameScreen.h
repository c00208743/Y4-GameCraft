#pragma once

/// <summary>
/// @EndGameScreen is to be played after the main menu---------currently coz theres no game screen
/// @author Jamie Murphy and Sean Regan
/// @Version 0.1
/// @brief Opening screen to display company logo
/// </summary>

#include "../Header/Game.h"
#include "../Header/KeyHandler.h"
#include <SFML\Graphics.hpp>

class Game;

class EndGameScreen
{
public:
	EndGameScreen(Game &game);
	~EndGameScreen();
	void update(sf::Time deltaTime);
	void render(sf::RenderWindow & window);
	void setStateBack();

private:

	Game *m_game;

	int m_currentSelect = 0;
	bool closeGame;
	sf::Time m_cumulativeTime;
	sf::Font myFont;
	sf::Text text;
	KeyHandler keys;

};
