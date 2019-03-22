#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

class SplashScreen
{
public:
	SplashScreen(Game & game);
	~SplashScreen();
	void update(double dt);
	void render(sf::RenderWindow &window);
private:
	sf::Texture m_Txt;
	sf::Sprite m_sprite;
	Game *m_game;
};