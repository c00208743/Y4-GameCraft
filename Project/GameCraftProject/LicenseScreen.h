#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

class LicenseScreen
{
public:
	LicenseScreen(Game &game);
	~LicenseScreen();
	void update(sf::Time dt);
	void render(sf::RenderWindow &window);
private:
	sf::Texture m_bgTxt;
	sf::Sprite m_bgSprite;
	sf::Time m_cumulativeTime;
	Game *m_game;
};