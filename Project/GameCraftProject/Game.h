#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ai.h"
#include "Grid.h"

// Class Files
#include "Hud.h"
#include "SplashScreen.h"
#include "LicenseScreen.h"
#include "GameScreen.h"

class LicenseScreen;
class SplashScreen;
class GameScreen;


enum class
	GameState
{
	none,
	License,
	Splash,
	GameScreen
};

class Game
{
public:
	// Public Methods
	Game();
	~Game();
	void run();
	GameState m_currentGameState;
	GameState m_previousGameState;
	void setGameState(GameState gamestate);

private:
	// Private Methods
	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	// Private Members
	sf::RenderWindow m_window; // main SFML window
	sf::View m_mainView;
	sf::View m_miniMapView;
	bool m_exitGame; // control exiting game


	Player *m_player;
	Ai * m_Ai;
	Grid *m_Grid;
	Game *m_game;

	License *m_License;
	Splash *m_Splash;
	GameScreen *m_game;


	// Hud
	Hud m_hud;
};

#endif // !GAME_H