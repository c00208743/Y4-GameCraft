#pragma once

/// <summary>
/// @Platform Class for all platforms and the ground in gameplay 
/// @author Jamie Murphy and Sean Regan
/// @Version 0.1
/// @brief Platforms to be used during gameplay
/// </summary>

#include "Game.h"

class Platform
{
public:
	Platform(float x, float y, int w, int h);
	~Platform();
	 
	void update();
	void render(sf::RenderWindow & window);
	sf::Vector2f getSize();
	sf::Vector2f getPos();

private:
	sf::Vector2f pos;
	float width;
	float height;
	sf::RectangleShape rect;

};