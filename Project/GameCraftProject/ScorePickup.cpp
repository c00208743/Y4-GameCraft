#include "ScorePickup.h"

ScorePickup::ScorePickup()
{
	m_active = false;
	m_maxLerpTime = 2.5f;
	m_currentTime = 0.0f;
	m_currentPercent = 0.0f;
	m_percentStep = 0.03f;
}

ScorePickup::~ScorePickup()
{
}

void ScorePickup::update(float dt)
{
	if (m_active && m_hit) {
		if (m_currentPercent < 1)
			m_currentPercent += m_percentStep;
		else {
			m_currentPercent = 1;
			m_active = false;
		}
		sf::Vector2f pos(
			lerpFloat(m_startPosition.x, m_goalPosition.x, m_currentPercent),
			lerpFloat(m_startPosition.y, m_goalPosition.y, m_currentPercent)
		);
		m_sprite.setPosition(pos);
	}
}

void ScorePickup::render(sf::RenderWindow & window)
{
	if (m_active)
		window.draw(m_sprite);
}

void ScorePickup::setActive(bool active)
{
}

void ScorePickup::init(sf::Vector2f pos, sf::Texture & texture, sf::SoundBuffer & buffer)
{
	m_sprite.setTexture(texture);
	m_sprite.setPosition(pos);
	m_startPosition = pos;
	m_active = true;
	m_hit = false;
	m_sound.setBuffer(buffer);
}

void ScorePickup::setSize(int w, int h)
{
	m_sprite.setScale(w / 24.f, h / 24.f);
}

void ScorePickup::collison()
{
	m_hit = true;
	m_goalPosition = sf::Vector2f(0, 0);
	m_sound.play();
}
