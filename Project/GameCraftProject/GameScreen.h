
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ai.h"
#include "Grid.h"

// Class Files
#include "Hud.h"

class GameScreen
{
public:
	// Public Methods
	GameScreen();
	~GameScreen();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow &window);
private:
	// Private Methods
	void processEvents();
	
	

	// Private Members
	sf::RenderWindow m_window; // main SFML window
	sf::View m_mainView;
	sf::View m_miniMapView;
	bool m_exitGame; // control exiting game


	Player *m_player;
	Ai * m_Ai;
	Grid *m_Grid;


	// Hud
	Hud m_hud;
};
