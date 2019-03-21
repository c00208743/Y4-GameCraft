#pragma once

/// <summary>
/// @Bullet Class handling bullet behaviour and rendering 
/// @author Jamie Murphy and Sean Regan
/// @Version 0.1
/// @brief An object to be used by the player to destory objects
/// </summary>

#include "Game.h"

class Bullet
{
public: 
	Bullet();
	~Bullet();
	void update();
	void render(sf::RenderWindow & window);
	void fire(float direction, sf::Vector2f pos);
	void checkCollision(sf::Vector2f size, sf::Vector2f pos);

private:
	float m_speed;
	sf::Vector2f m_size;
	sf::Vector2f m_pos;
	sf::RectangleShape m_rect;
	bool m_alive;
};