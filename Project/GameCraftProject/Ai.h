#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Grid.h"

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
	Ai(Grid &m_Grid);
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
	Grid *m_Grid;
	Direction m_currentDir = d_IDLE;
	int timer = 0;
	int rtimer = 0;
	int r = 0;
	int pGridX, pGridY = 0;
};