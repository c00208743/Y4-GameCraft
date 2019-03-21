#pragma once

/// <summary>
/// @MainMenuScreen Title screen to be played after the title screen
/// @author Jamie Murphy and Sean Regan
/// @Version 0.1
/// @brief Dsiplay player options
/// </summary>

#include "../Header/Game.h"
#include <SFML\Graphics.hpp>
#include "..\Header\GUI.h"

class Game;

class MainMenuScreen
{
public:
	MainMenuScreen(Game &game);
	~MainMenuScreen();
	void update(sf::Time deltaTime);
	void goToLevelSelect();
	void quit();
	void render(sf::RenderWindow & window);
	

private:

	Game *m_game;
	GUI m_gui;
	Label *m_title;
	Button *m_play;
	Button *m_quit;
	int m_currentSelect = 0;
	sf::Time m_cumulativeTime;
	sf::Font myFont;
	sf::Font myFont2;
	sf::Text text[3];
	//shader
	float updateShader;
	sf::Shader shader;
	sf::Texture shaderTxt;
	sf::Sprite shaderSprite;



};
