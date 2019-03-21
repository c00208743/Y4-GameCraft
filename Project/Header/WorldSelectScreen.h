#pragma once

/// <summary>
/// @WorldSelectScreen to be played after the main menu when play game is selected
/// @author Jamie Murphy and Sean Regan
/// @Version 0.1
/// @brief Opening screen to display company logo
/// </summary>

#include "../Header/Game.h"
#include "../Header/KeyHandler.h"
#include <SFML\Graphics.hpp>
#include "GUI.h"

class Game;

class WorldSelectScreen
{
public:
	WorldSelectScreen(Game &game);
	~WorldSelectScreen();
	void update(sf::Time deltaTime);
	void goToGameScreen();
	void goToMainMenu();
	void render(sf::RenderWindow & window);

private:

	Game *m_game;

	GUI m_gui;
	Label *m_title;
	Button *m_worldOne;
	Button *m_worldTwo;
	Button *m_worldThree;
	Button *m_back;

	int m_currentSelect = 0;
	bool conToMenu;
	sf::Time m_cumulativeTime;
	sf::Font myFont;
	sf::Font myFont2;
	sf::Text text[5];
	KeyHandler keys;
	//Background image
	sf::Texture m_Texture;//background texture
	sf::Sprite m_Sprite;//sprite for texture

};
