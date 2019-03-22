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
	int m_currentLevel;
	void run();
	void update(float dt);
	void loadNextLevel();
	void loadLevel(int level[12][16]);
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
	std::vector<int> map;
	void lerpAllPickups();

	bool goalReached = false;

	int map1[12][16] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };

	int map2[12][16] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
		{ 1,0,0,0,0,0,0,1,2,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };

	int map3[12][16] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,1,2,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
		{ 1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };

	int map4[12][16] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1 },
		{ 1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
		{ 1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,1,2,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };

	int map5[12][16] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1 },
		{ 1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,2,0,0,0,0,0,0,0,0,0,0,1,1 },
		{ 1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };
	std::map<std::pair<int, int>, ScorePickup> m_scorePickups;

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

	void initScorePickups();
	sf::Texture m_scoreTexture;
	sf::SoundBuffer m_buffer;
};