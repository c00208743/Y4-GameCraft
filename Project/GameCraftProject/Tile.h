#pragma once
#pragma once
#include <SFML\Graphics.hpp>
#include <sstream>

enum State
{
	NONE,
	GOAL,
	WALL
};


class Tile
{
public:
	Tile(float x, float y, int tileSize, float m_tileScale, int xPos, int yPos, sf::Font &font);
	~Tile();

	void update();
	void mouseDetection(sf::Vector2i mousePos, int val);

	void render(sf::RenderWindow &window);

	void setCurrentState(State s);
	State getCurrentState();



	sf::Vector2f m_position;
	sf::RectangleShape rectangle;

	State m_currentState = NONE;

	int m_tileSize;
	float m_tileScale;


	int m_xPos;
	int m_yPos;

	float m_rotation = 0;

	sf::RectangleShape vector;


	sf::Vector2f m_velocity;

private:

};