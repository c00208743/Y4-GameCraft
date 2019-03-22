#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Grid.h"

// Class Files
#include "Hud.h"

class Game
{
public:
	// Public Methods
	Game();
	~Game();
	void run();
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
	Grid *m_Grid;


	// Hud
	Hud m_hud;
};

#endif // !GAME_H