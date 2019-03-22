#include "ScorePickup.h"

ScorePickup::ScorePickup()
{
	m_active = false;
}

ScorePickup::~ScorePickup()
{
}

void ScorePickup::update(float dt)
{
}

void ScorePickup::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

void ScorePickup::setActive(bool active)
{
}

void ScorePickup::init(sf::Vector2f pos, sf::Texture & texture)
{
	m_sprite.setTexture(texture);
	m_sprite.setPosition(pos);
	m_active = true;
}

void ScorePickup::setSize(int w, int h)
{
	m_sprite.setScale(w / 24.f, h / 24.f);
}
