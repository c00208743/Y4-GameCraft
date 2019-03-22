#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

enum Direction {
	d_UP,
	d_DOWN,
	d_LEFT,
	d_RIGHT,
	d_IDLE
};

class Ai
{
public:
	Ai();
	~Ai();
	void update();
	void move();
	void collision();
	void setDirection();
	Direction getDirection();
	void render(sf::RenderWindow &window);
	sf::Vector2f getPos();

private:
	sf::Vector2f m_pos;
	sf::Vector2f velocity;
	sf::Texture m_Txt;
	sf::Sprite m_sprite;

	Direction m_currentDir = d_IDLE;
	int timer = 0;
	int r = 0;
};