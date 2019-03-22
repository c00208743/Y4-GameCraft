#include "LicenseScreen.h"
#include <iostream>

LicenseScreen::LicenseScreen(Game & game) :
	m_game(&game)
{
	m_bgTxt.loadFromFile("./resources/images/globe.png");
	m_bgSprite.setTexture(m_bgTxt);
	m_bgSprite.setPosition(-250, 500);
	m_bgSprite.setPosition(650, 320);

}

LicenseScreen::~LicenseScreen()
{
	std::cout << "destructing Splash" << std::endl;
}

void LicenseScreen::update(sf::Time deltaTime)
{
	m_cumulativeTime += deltaTime;
	

	if (m_cumulativeTime.asSeconds() > 4)
	{
		m_game->setGameState(GameState::Splash);

	}

}
//Switches the gamestate when this method is called
//void License::anyKeyPress()
//{
//	m_game->setGameState(GameState::Help);
//}

void LicenseScreen::render(sf::RenderWindow & window)
{
	window.draw(m_bgSprite);
	
}