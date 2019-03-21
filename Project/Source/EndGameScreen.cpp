#include "../Header/EndGameScreen.h"

/// <summary>
/// @EndGameScreen to be played after the main menu
/// @author Jamie Murphy and Sean Regan
/// @Version 0.1
/// @brief Opening screen to display 
/// </summary>


//constructs the splash screen
EndGameScreen::EndGameScreen(Game & game) : m_game(&game)
{
	m_currentSelect = 0;

	// Load from a font file on disk
	if (!myFont.loadFromFile("Asset/Fonts/Batman.ttf"))
	{
		// Error...
	}
	//const sf::Color &colour = sf::Color::Black;

	text = sf::Text("END GAME SCREEN", myFont, 40);
	text.setPosition(200, 200);

	keys = KeyHandler();
}

//destructor
EndGameScreen::~EndGameScreen()
{
}

//updates screen
void EndGameScreen::update(sf::Time deltaTime)
{
	//doesnt need a change games state 
	// should close application
	m_cumulativeTime += deltaTime;

	if (m_cumulativeTime.asSeconds() > 5)
	{
		closeGame = true;
	}
}

//draws window
void EndGameScreen::render(sf::RenderWindow & window)
{
	window.draw(text);
	if (closeGame == true)
	{
		window.close();
	}
}



//sets gamestate
void EndGameScreen::setStateBack()
{
	//m_game->changeGameState(GameState::TheMenu);
}