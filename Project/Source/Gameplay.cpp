#include "../Header/Gameplay.h"
#include "../Header/Platform.h"
#include "../Header/Player.h"
#include "../Header/LevelLoader.h"


/// <summary>
/// @Gameplay screen to be played before the Main Menu screen 
/// @author Jamie, Eric, Aaron, Brendan, Jack and Sean
/// @Version 0.1
/// @brief Gameplay
/// </summary>


//constructs the splash screen
GameplayScreen::GameplayScreen(Game & game) : m_game(&game)
{
	//loading yaml file
	int currentLevel = 1;
	if (!LevelLoader::load(currentLevel, m_level))
	{
		return;
	}
	m_currentSelect = 0;

	// Load from a font file on disk
	if (!myFont.loadFromFile("Asset/Fonts/powerful.ttf"))
	{
		// Error...
	}

	text = sf::Text("TEST", myFont, 100);
	text.setPosition(475, 400);

	m_cumulativeTime = sf::Time::Zero;
	
	GeneratePlatform();
	m_ground = make_unique<Platform>(0.0f, 1350.0f, 400.0f, 90.0f);
	m_player = make_unique<Player>();
	
}

//destructor
GameplayScreen::~GameplayScreen()
{
}

//updates screen
void GameplayScreen::update(sf::Time deltaTime)
{
	m_cumulativeTime += deltaTime;
	
	m_ground->update();
	m_player->checkCollision(m_ground->getSize(), m_ground->getPos());
	for (int i = 0; i < m_platform.size(); i++)
	{
		m_platform[i].update();
		m_player->checkCollision(m_platform[i].getSize(), m_platform[i].getPos());
	}

	m_player->update();

}

void GameplayScreen::GeneratePlatform()
{

	//for (PlatformData const &node : m_level.m_platform)//load in node data from yaml file
	for (int i = 0; i < m_level.m_platform.size(); i++)
	{
		float x = m_level.m_platform[i].m_position.x;
		float y = m_level.m_platform[i].m_position.y;
		float w = m_level.m_platform[i].m_size.x;
		float h = m_level.m_platform[i].m_size.y;
		Platform temp = Platform(x, y, w, h);
		m_platform.push_back(temp);
	}

}

//draws window
void GameplayScreen::render(sf::RenderWindow & window)
{
	m_ground->render(window);
	for (int i = 0; i < m_platform.size(); i++)
	{
		m_platform[i].render(window);
	}
	m_player->render(window);


	window.draw(text);
}
