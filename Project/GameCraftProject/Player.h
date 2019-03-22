#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

enum Dir {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	IDLE
};

class Player
{
public:
	Player();
	~Player();
	void update();
	void move();
	void collision();
	void setDirection();
	Dir getDirection();
	void render(sf::RenderWindow &window);
	sf::Vector2f getPos();

private:
	sf::Vector2f m_pos;
	sf::Vector2f velocity;
	sf::Texture m_Txt;
	sf::Sprite m_sprite;
	Dir m_currentDir = IDLE;
};