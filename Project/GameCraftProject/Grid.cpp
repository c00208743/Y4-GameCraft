
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
	int mySampleMap[12][16] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{ 1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
		{ 1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
		{ 1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
		{ 1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
		{ 1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1},
		{ 1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1},
		{ 1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1},
		{ 1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1},
		{ 1,1,1,1,1,1,1,1,1,0,2,1,1,1,1,1},
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
		
		

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			m_tileGrid[i][j] = new Tile(x, y+50, m_tileSize, m_tileScale, i, j, m_font);
			x = x + m_tileSize * m_tileScale;

			if (mySampleMap[i][j] == 1)
			{
				m_tileGrid[i][j]->setCurrentState(WALL);
			}
			else if (mySampleMap[i][j] == 0)
			{
				m_tileGrid[i][j]->setCurrentState(NONE);
			}
			else if (mySampleMap[i][j] == 2)
			{
				m_tileGrid[i][j]->setCurrentState(GOAL);
			}

		}

		x = 0;
		y = y + m_tileSize * m_tileScale;
	}

	//for (int i = 0; i < m_gridSize; i++)
	//{

		//m_tileGrid[0][i]->setCurrentState(OBSTACLE);
		//m_tileGrid[i][0]->setCurrentState(OBSTACLE);
		//m_tileGrid[m_gridSize - 1][i]->setCurrentState(OBSTACLE);
		//m_tileGrid[i][m_gridSize - 1]->setCurrentState(OBSTACLE);
	//}


	//initGrid();


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

}