#include "Game.h"

/// <summary>
/// Constructor for the game object
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "GameCraft" },
	m_currentGameState(GameState::License),
	m_exitGame{ false } // When true game will exit
{
	m_License = new LicenseScreen(*this);
	m_Splash = new SplashScreen(*this);
	m_game = new GameScreen();
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
		}
	}
}

void Game::setGameState(GameState gameState)
{
	m_currentGameState = gameState;
}

/// <summary>
/// Update loop for the game
/// </summary>
/// <param name="t_deltaTime">deltatime</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
	switch (m_currentGameState)
	{
	case GameState::License:
		m_License->update(t_deltaTime);
		break;
	case GameState::Splash:
		m_Splash->update(t_deltaTime);
		break;
	case GameState::GameScreen:
		m_game->update(t_deltaTime);
		break;
	default:
		break;

	}
}

/// <summary>
/// Draw loop for the game
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);
	switch (m_currentGameState)
	{
	case GameState::License:
		m_License->render(m_window);
		break;
	case GameState::Splash:
		m_Splash->render(m_window);
		break;
	case GameState::GameScreen:
		m_game->render(m_window);
		break;
	default:
		break;

	}
	m_window.display();
}
	