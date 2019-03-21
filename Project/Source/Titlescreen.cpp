#include "../Header/Titlescreen.h"

/// <summary>
/// @SplashScreen Title screen to be played before the main menu
/// @author Jamie Murphy and Sean Regan
/// @Version 0.1
/// @brief Opening screen to display 
/// </summary>


//constructs the splash screen
Titlescreen::Titlescreen(Game & game) : m_game(&game)
{
	m_currentSelect = 0;

	// Load from a font file on disk
	if (!myFont.loadFromFile("Asset/Fonts/powerful.ttf"))
	{
		// Error...
	}

	if (!myFont2.loadFromFile("Asset/Fonts/Batman.ttf"))
	{
		// Error...
	}


	text[0] = sf::Text("LINNY AND KARLTON", myFont, 100);
	text[0].setPosition(475, 400);

	text[1] = sf::Text("[Press) (Space] [to) (Continue]", myFont2, 100);
	text[1].setPosition(300, 600);
	text[1].setFillColor(sf::Color::Black);

	keys = KeyHandler();
	m_cumulativeTime = sf::Time::Zero;
}

//destructor
Titlescreen::~Titlescreen()
{
}

//updates screen
void Titlescreen::update(sf::Time deltaTime)
{
	m_cumulativeTime += deltaTime;
	std::cout << sf::Keyboard::isKeyPressed(sf::Keyboard::Space) << std::endl;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_game->changeGameState(GameState::MainMenu);
	}
	if (m_cumulativeTime.asSeconds() > 2)
	{
		text[1].setFillColor(sf::Color::White);
	
	}
}

//draws window
void Titlescreen::render(sf::RenderWindow & window)
{
	for (int i = 0; i < sizeof(text)/ sizeof(text[0]); i++)
	{
		window.draw(text[i]);
	}
	
}



//sets gamestate
void Titlescreen::setStateBack()
{
	//m_game->changeGameState(GameState::TheMenu);
}