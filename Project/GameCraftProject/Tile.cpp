#include "Tile.h"
#include <iostream>
Tile::Tile(float x, float y, int tileSize, float tileScale, int xPos, int yPos, sf::Font &font) :
	m_position(x, y),
	m_tileSize(tileSize),
	m_tileScale(tileScale),
	m_xPos(xPos),
	m_yPos(yPos)
{
	rectangle.setSize(sf::Vector2f(m_tileSize * m_tileScale, m_tileSize * m_tileScale));
	rectangle.setOutlineThickness(2);
	rectangle.setOutlineColor(sf::Color(200, 200, 200));
	rectangle.setPosition(x, y);
}

Tile::~Tile()
{

}


/// <summary>
/// Sets the current state of the tile
/// depending on the tile type the tile is coloured differently 
/// 
/// </summary>
/// <param name="s"></param>
void Tile::setCurrentState(State s)
{
	m_currentState = s;

	switch (m_currentState)
	{
	case NONE:
		rectangle.setFillColor(sf::Color(255, 255, 255));
		break;
	case GOAL:
		rectangle.setFillColor(sf::Color::Red);
		break;
	case WALL:
		rectangle.setFillColor(sf::Color(45, 45, 45));
		//rectangle.setOutlineThickness(0);
		break;
	case TRAP:
		rectangle.setFillColor(sf::Color(0,255, 0, 255));
		break;
	default:
		break;
	}
}

/// <summary>
/// Get current state of the tile
/// </summary>
/// <returns></returns>
State Tile::getCurrentState()
{
	return m_currentState;
}

/// <summary>
/// Draws the vectors of the flowfield on the tile
/// If commented outthe red vectors will disappear 
/// </summary>
/// <param name="window"></param>
void Tile::render(sf::RenderWindow &window)
{
	window.draw(rectangle);
}