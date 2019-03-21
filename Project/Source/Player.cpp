#include "../Header/Player.h"

Player::Player()
{
	m_mass = 20.0f;
	m_speed = 10.0f;
	m_size = sf::Vector2f(25, 50);
	m_pos = sf::Vector2f(50, 1200);
	m_velocity = sf::Vector2f(0, 0);
	m_accel = sf::Vector2f(0, 0);
	m_rect = sf::RectangleShape(m_size);
	m_rect.setPosition(m_pos);
	//m_rect.setFillColor(sf::Color::Green);
	m_gravity = sf::Vector2f(0, 0.1f * m_mass);
	m_jumpForce = sf::Vector2f(0, -5.0f * m_mass);
	m_moveForce = sf::Vector2f(0.5f * m_mass, 0.0f);
	m_friction = sf::Vector2f(0.3f * m_mass, 0.0f);
	m_fall = true;
	m_jumping = false;
	m_movingLeft = true;
	m_movingRight = true;
	m_direction = 1.0f;

	if (!m_Texture.loadFromFile("Asset/Images/Player.png"))
	{
		std::string s("error loading texture from file");
		throw std::exception(s.c_str());
	}
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setPosition(m_velocity);

	m_bullet = make_unique<Bullet>();

}

Player::~Player()
{

}


void Player::render(sf::RenderWindow & window)
{
	window.draw(m_Sprite);
	m_bullet->render(window);
}

void Player::applyForce(sf::Vector2f force)
{
	sf::Vector2f f = force / m_mass;
	m_accel += f;
}

void Player::update()
{	

	m_bullet->update();

	fire();
	jump(); 
	moveLeft();
	moveRight();

	if (!m_fall && !m_jumping)
	{
		if (m_velocity.x < 0)
		{
			applyForce(m_friction);
		}
		else if (m_velocity.x > 0)
		{
			applyForce(-m_friction);
		}

		if (m_velocity.x < 0.15f && m_velocity.x > -0.15f)
		{
			m_velocity.x = 0;
		}

	}

	if (m_fall)
	{
		applyForce(m_gravity);
	}
	else
	{
		m_velocity = sf::Vector2f(m_velocity.x, 0.0f);
		m_fall = true;
	}

	m_velocity += m_accel;
	m_pos += m_velocity;
	m_accel = sf::Vector2f(0.0f, 0.0f);

	m_Sprite.setPosition(m_pos);
}

void Player::checkCollision(sf::Vector2f size, sf::Vector2f pos)
{
	m_bullet->checkCollision(size, pos);

	float w = 0.5f * (m_size.x + size.x);
	float h = 0.5f * (m_size.y + size.y);
	float dx = (m_pos.x + (m_size.x / 2)) - (pos.x + (size.x / 2));
	float dy = (m_pos.y + (m_size.y / 2)) - (pos.y + (size.y / 2));

	if (abs(dx) <= w && abs(dy) <= h)
	{
		/* collision! */
		float wy = w * dy;
		float hx = h * dx;

		if (wy > hx)
		{
			if (wy > -hx)
			{
				// Top 
				m_velocity.y = 0.0f;
				m_jumping = true;
				m_fall = true;
				m_pos.y = pos.y + size.y;
			}
			else if ( wy < -hx)
			{
				// Left
				m_movingRight = false;
				m_velocity.x = 0.0f;
				m_pos.x = pos.x - m_size.x;
			}
		}
		else if (wy < hx)
		{
			if (wy > -hx)
			{
				// Right
				m_movingLeft = false;
				m_velocity.x = 0.0f;
				m_pos.x = pos.x + size.x;
			}
			else if(wy < -hx)
			{
				// Bottom
				m_fall = false;
				m_jumping = false;
				m_pos.y = pos.y - m_size.y;
			}
		}
	}

}

void Player::jump()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (!m_jumping)
		{
			applyForce(m_jumpForce);
			m_jumping = true;
			
		}
	}
}

void Player::moveLeft()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_velocity.x > -20 && m_movingLeft)
	{
		applyForce(-m_moveForce);
		//m_fall = true;
		m_movingRight = true;

		m_direction = -1.0f;
	}
	m_movingLeft = true;
}

void Player::moveRight()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_velocity.x < 20 && m_movingRight)
	{
		applyForce(m_moveForce);
		//m_fall = true;
		m_movingLeft = true;
		m_direction = 1.0f;
	}
	m_movingRight = true;
}

void Player::fire()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_bullet->fire(m_direction, m_pos);
	}
}