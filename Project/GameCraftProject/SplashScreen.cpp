#include "SplashScreen.h"

SplashScreen::SplashScreen(Game &game):
	m_game(&game)
{
	if(!m_Txt.loadFromFile(".assets/"))
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::update(double dt)
{
}

void SplashScreen::render(sf::RenderWindow & window)
{
}
