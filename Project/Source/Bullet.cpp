#include "../Header/Bullet.h"

Bullet::Bullet()
{
	m_speed = 50.0f;
	m_size = sf::Vector2f(5.0f, 5.0f);
	m_pos = sf::Vector2f(100.0f, 100.0f);
	m_alive = false;
	m_rect = sf::RectangleShape(m_size);
	m_rect.setPosition(m_pos);
	m_rect.setFillColor(sf::Color::Red);
}

Bullet::~Bullet()
{

}

void Bullet::render(sf::RenderWindow & window)
{
	if (m_alive)
	{
		window.draw(m_rect);
	}
}

void Bullet::update()
{
	if (m_alive)
	{
		m_pos.x += m_speed;

		m_rect.setPosition(m_pos);
	}
}

void Bullet::checkCollision(sf::Vector2f size, sf::Vector2f pos)
{

	float w = 0.5f * (m_size.x + size.x);
	float h = 0.5f * (m_size.y + size.y);
	float dx = (m_pos.x + (m_size.x / 2)) - (pos.x + (size.x / 2));
	float dy = (m_pos.y + (m_size.y / 2)) - (pos.y + (size.y / 2));

	if (abs(dx) <= w && abs(dy) <= h)
	{
		/* collision! */
		m_alive = false;

		float wy = w * dy;
		float hx = h * dx;

		if (wy > hx)
		{
			if (wy > -hx)
			{
				// Top 
			}
			else if (wy < -hx)
			{
				// Left
			}
		}
		else if (wy < hx)
		{
			if (wy > -hx)
			{
				// Right
			}
			else if (wy < -hx)
			{
				// Bottom
			}
		}
	}

}

void Bullet::fire(float direction, sf::Vector2f pos)
{
	m_speed = 50.0f;

	m_speed *= direction;
	m_pos = pos;
	m_alive = true;
}