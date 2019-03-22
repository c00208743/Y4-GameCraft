#include "GameScreen.h"

/// <summary>
/// Constructor for the game object
/// </summary>
GameScreen::GameScreen()
{
	m_Ai = new Ai();
	m_Grid = new Grid();
	m_player = new Player(*m_Grid);
}

/// <summary>
/// Destructor for the game object
/// </summary>
GameScreen::~GameScreen() {}

/// <summary>
/// Process the game events
/// </summary>
void GameScreen::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}
	}
}

/// <summary>
/// Update loop for the game
/// </summary>
/// <param name="t_deltaTime">deltatime</param>
void GameScreen::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
	m_player->update();
	m_Ai->update();
}

/// <summary>
/// Draw loop for the game
/// </summary>
void GameScreen::render(sf::RenderWindow &m_window)
{
	m_window.clear(sf::Color::Black);
	m_Grid->render(m_window);
	m_player->render(m_window);
	m_Ai->render(m_window);
	m_hud.render(m_window);
	m_window.display();
}