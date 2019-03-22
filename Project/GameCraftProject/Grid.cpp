
#include "Game.h"
#include <limits>
#include <list>
#include <queue>
#include "Grid.h"

/// <summary>
/// 
/// </summary>
Grid::Grid()
{
	//loadNextLevel(0);
	//loadLevel(map1);
	m_currentLevel = 0;
	loadNextLevel();
 

}
void Grid::loadNextLevel() {

	switch (m_currentLevel)
	{
	case 0:
		loadLevel(map1);
		m_currentLevel = 0;
		break;
	case 1:
		loadLevel(map2);
		m_currentLevel = 2;
		break;
	case 2:
		loadLevel(map3);
		m_currentLevel = 3;
		break;
	case 3:
		loadLevel(map4);
		m_currentLevel = 4;
	case 4:
		loadLevel(map5);
		m_currentLevel = 4;
		break;
	default:
		break;
	}

	
}
void Grid::loadLevel(int level[12][16]) {

	if (!m_scoreTexture.loadFromFile("Assets/Images/Pickups/coin 2.png")) {
		std::cerr << "Error: Failed to load score pickup png" << std::endl;
	}
	if (!m_buffer.loadFromFile("Assets/Sounds/Picked Coin Echo.wav")) {
		std::cerr << "Error: Failed to load Picked Coin Echo.wav" << std::endl;
	}
		
		

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			m_tileGrid[i][j] = new Tile(x, y+50, m_tileSize, m_tileScale, i, j, m_font);
			x = x + m_tileSize * m_tileScale;

			if (level[i][j] == 1)
			{
				m_tileGrid[i][j]->setCurrentState(WALL);
			}
			else if (level[i][j] == 0)
			{
				m_tileGrid[i][j]->setCurrentState(NONE);
			}
			else if (level[i][j] == 2)
			{
				m_tileGrid[i][j]->setCurrentState(GOAL);
			}
			else if (level[i][j] == 3)
			{
				m_tileGrid[i][j]->setCurrentState(TRAP);
			}

		}

		x = 0;
		y = y + m_tileSize * m_tileScale;
	}

	initScorePickups();



}


void Grid::update(float dt)
{
	for (auto & pickup : m_scorePickups) {
		m_scorePickups[pickup.first].update(dt);
	}
}

/// <summary>
/// Renders all the tiles in the map only if they are in the game view
/// This will improve performance
/// </summary>
void Grid::render(sf::RenderWindow &window)
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 16; j++)
		{

			m_tileGrid[i][j]->render(window);

		}

	}

	for (auto & scorePickup : m_scorePickups) {
		m_scorePickups[scorePickup.first].render(window);
	}

}

void Grid::initScorePickups()
{
	m_scorePickups.clear();
	for (auto & row : m_tileGrid) {
		for (auto & col : row) {
			if (col->m_currentState == NONE) {
				ScorePickup s;
				s.init(col->m_position, m_scoreTexture, m_buffer);
				s.setSize(50, 50);
				
				m_scorePickups[std::make_pair(col->m_xPos, col->m_yPos)] = s;
			}
		}
	}
}

void Grid::lerpAllPickups()
{
	for (auto & scorePickup : m_scorePickups) {
		m_scorePickups[scorePickup.first].collison();
	}
}
