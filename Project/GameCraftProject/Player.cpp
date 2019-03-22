#include "Player.h"

Player::Player()
{
	m_pos = sf::Vector2f(50, 100);
	velocity = sf::Vector2f(0, 0);

	if (!m_Txt.loadFromFile("./assets/playerImg.png"))
	{
		std::cout << "Error loading player Image";
	}
	m_sprite.setTexture(m_Txt);
	m_sprite.setPosition(m_pos);
}

Player::~Player()
{
}

void Player::update()
{
	move();
	collision();
	setDirection();
	m_sprite.setPosition(m_pos);
}

void Player::setDirection()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_currentDir ==IDLE)
	{
		m_currentDir = UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_currentDir == IDLE)
	{
		m_currentDir = DOWN;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_currentDir == IDLE)
	{
		m_currentDir = LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_currentDir == IDLE)
	{
		m_currentDir = RIGHT;
	}
}

void Player::move()
{
	if (m_currentDir == LEFT)
	{
		velocity.x = -10;
		velocity.y = 0;
		m_pos.x +=  velocity.x;
		m_pos.y +=  velocity.y;
	}
	else if (m_currentDir == RIGHT)
	{
		velocity.x = 10;
		velocity.y = 0;
		m_pos.x +=  velocity.x;
		m_pos.y +=  velocity.y;
	}
	else if (m_currentDir == UP)
	{
		velocity.x = 0;
		velocity.y = -10;
		m_pos.x +=  velocity.x;
		m_pos.y +=  velocity.y;
	}
	else if (m_currentDir == DOWN)
	{
		velocity.x = 0;
		velocity.y = 10;
		m_pos.x +=  velocity.x;
		m_pos.y +=  velocity.y;
	}
}

void Player::collision()
{
	if (m_pos.x >= 750 && velocity.x > 0)
	{
		m_pos.x = 740;
		m_currentDir = IDLE;
	}
	else if (m_pos.x <= 40 && velocity.x < 0)
	{
		m_pos.x = 0;
		m_currentDir = IDLE;
	}

	if (m_pos.y >= 550 && velocity.y > 0)
	{
		m_pos.y = 540;
		m_currentDir = IDLE;
	}
	else if (m_pos.y <= 40 && velocity.y < 0)
	{
		m_pos.y = 0;
		m_currentDir = IDLE;
	}
}

sf::Vector2f Player::getPos()
{
	return m_pos;
}

void Player::render(sf::RenderWindow &window)
{
	window.draw(m_sprite);
}
