#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include "Tile.h"

#include "ScorePickup.h"

using namespace std;

class Grid
{
public:
	Grid();
	void run();
	void update(float dt);
	void render(sf::RenderWindow &window);
	bool inView(sf::Vector2f position, sf::View &m_gameView);

	void processGameEvents(sf::Event& event);
	void initGrid(int posX, int posY);
	void updateCost(int posX, int posY, int radius);
	static const int m_gridSize = 12;
	static const int m_tileSize = 50;
	Tile *m_tileGrid[m_gridSize][16];
	std::vector <Tile*> m_spawnPoints;
	std::vector <Tile*> m_nestPoints;
	Tile* m_sweeperSpawn;

	std::ofstream myMap;
	void lerpAllPickups();
private:

	void processEvents();
	void reset();
	void getPath(Tile m_startTile);

protected:

	float m_tileScale = 1;

	int x = 0;
	int y = 0;

	int m_tilePosX = 0;
	int m_tilePosY = 0;

	sf::Vector2i m_mousePos;

	Tile * m_startTile;
	Tile * m_goalTile;

	sf::Font m_font;

	bool m_leftPress = false;
	bool m_rightPress = false;
	sf::View m_gameView;
	sf::View miniMapView;
	std::vector<ScorePickup> m_scorePickups;
	void initScorePickups();
	sf::Texture m_scoreTexture;
	sf::SoundBuffer m_buffer;
};