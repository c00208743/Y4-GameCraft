#include "Hud.h"
#include <iostream>

Hud::Hud()
{
	if (!m_font.loadFromFile("Assets/Fonts/LEGO BRIX.ttf")) {
		std::cerr << "ERROR: Faile to load font LEGO BRIX.ttf" << std::endl;
	}
	else {
		m_fontColour = sf::Color(242, 191, 9, 255);
		m_backgroundColour = sf::Color(0, 0, 255, 255);

		// set fonts
		m_scoreText.setFont(m_font);
		m_timeText.setFont(m_font);

		// set colours
		m_scoreText.setFillColor(m_fontColour);
		m_timeText.setFillColor(m_fontColour);

		// Set strings
		m_scoreText.setString(m_scoreString);
		m_timeText.setString(m_timeString);


		// Init backfgorund
		m_hudBackground.setPosition(0, 0);
		m_hudBackground.setSize(sf::Vector2f(800, 50));
		m_hudBackground.setFillColor(m_backgroundColour);

		// set Scales
		int maxCharacterSize = m_hudBackground.getSize().y / 1.25f;
		if (maxCharacterSize > 50)
			maxCharacterSize = 50;
		m_scoreText.setCharacterSize(maxCharacterSize);
		m_timeText.setCharacterSize(maxCharacterSize);

		// Set positions
		sf::Vector2f backgroundPos = m_hudBackground.getPosition();
		sf::Vector2f backgroundSize = m_hudBackground.getSize();

		float textY = backgroundPos.y + (backgroundSize.y - (backgroundSize.y / 1.25));
		m_scoreText.setPosition(sf::Vector2f(backgroundPos.x + 10, textY));
		int w = m_timeText.getLocalBounds().width;
		m_timeText.setPosition(sf::Vector2f(backgroundPos.x + backgroundSize.x - (m_timeText.getGlobalBounds().width * 2), textY));
	}
}

Hud::~Hud()
{
}

void Hud::update(float dt)
{
	m_timeSinceStart += dt;
	m_timeText.setString(m_timeString + std::to_string((int)m_timeSinceStart));
}

void Hud::render(sf::RenderWindow & window)
{
	window.draw(m_hudBackground);
	window.draw(m_scoreText);
	window.draw(m_timeText);
}

void Hud::setHudSize(int w, int h)
{
}

void Hud::setPosition(sf::Vector2f position)
{
}

void Hud::setScore(const int score)
{
	m_score = score;
}

void Hud::addScore(const int increment)
{
	m_score += increment;
}
