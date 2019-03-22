#include "Game.h"

/// <summary>
/// Constructor for the game object
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "GameCraft" },
	m_exitGame{ false } // When true game will exit
{
	m_Ai = new Ai();
	m_Grid = new Grid();
	m_player = new Player(*m_Grid);
}

/// <summary>
/// Destructor for the game object
/// </summary>
Game::~Game() {}

/// <summary>
/// Run the Game
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // As many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // At least 60 fps
			update(timePerFrame); // 60 fps
		}
		render(); // As many as possible
	}
}

/// <summary>
/// Process the game events
/// </summary>
void Game::processEvents()
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
			if (sf::Keyboard::Enter == event.key.code) {
				m_Grid->lerpAllPickups();
			}
		}
	}
}

/// <summary>
/// Update loop for the game
/// </summary>
/// <param name="t_deltaTime">deltatime</param>
void Game::update(sf::Time t_deltaTime)
{
	float dt = t_deltaTime.asSeconds();
	if (m_exitGame)
	{
		m_window.close();
	}
	m_player->update();
	m_Ai->update();
	m_Grid->update(dt);
	m_hud.update(dt);
	m_hud.setScore(m_player->m_score);
}

/// <summary>
/// Draw loop for the game
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);
	m_Grid->render(m_window);
	m_player->render(m_window);
	m_Ai->render(m_window);
	m_hud.render(m_window);
	m_window.display();
}