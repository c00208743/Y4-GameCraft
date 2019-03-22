#include "Player.h"

Player::Player(Grid &Grid):
	m_Grid(&Grid)
{
	m_pos = sf::Vector2f(75, 125);
	velocity = sf::Vector2f(0, 0);

	if (!m_Txt.loadFromFile("./assets/playerImg.png"))
	{
		std::cout << "Error loading player Image";
	}
	m_sprite.setTexture(m_Txt);
	m_sprite.setPosition(m_pos);
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2, m_sprite.getTextureRect().height / 2);

	pGridX = floor(m_pos.x / m_Grid->m_tileSize);
	pGridY = floor((m_pos.y-50) / m_Grid->m_tileSize);
}

Player::~Player()
{
}

void Player::update()
{
	move();
	collision();
	setDirection();
	m_sprite.setPosition(m_sprite.getPosition().x + velocity.x, m_sprite.getPosition().y + velocity.y);
	pGridX = floor(m_sprite.getPosition().x / m_Grid->m_tileSize);
	pGridY = floor((m_sprite.getPosition().y -40) / m_Grid->m_tileSize);
	
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
	if (m_currentDir == IDLE)
	{
		velocity.x = 0;
		velocity.y = 0;
	}
}

void Player::collision()
{
	if (m_currentDir == RIGHT && m_Grid->m_tileGrid[pGridY][pGridX + 1]->getCurrentState() == WALL)
	{
		if (m_pos.x - m_Grid->m_tileGrid[pGridY][pGridX + 1]->m_position.x <= 30)
		{
			m_sprite.setPosition(m_Grid->m_tileGrid[pGridY][pGridX + 1]->m_position.x -35, m_sprite.getPosition().y);
		}
			m_currentDir = IDLE;
	}
	if (m_currentDir == LEFT && m_Grid->m_tileGrid[pGridY][pGridX - 1]->getCurrentState() == WALL)
	{
		if (m_pos.x - m_Grid->m_tileGrid[pGridY][pGridX - 1]->m_position.x >= 30)
		{
			m_sprite.setPosition(m_Grid->m_tileGrid[pGridY][pGridX - 1]->m_position.x + 85, m_sprite.getPosition().y);
		}
		m_currentDir = IDLE;
			
	}

	if (m_currentDir == DOWN &&m_Grid->m_tileGrid[pGridY+1][pGridX]->getCurrentState() == WALL)
	{
		if (m_pos.x - m_Grid->m_tileGrid[pGridY+1][pGridX]->m_position.y <= 30)
		{
			m_sprite.setPosition(m_sprite.getPosition().x , m_Grid->m_tileGrid[pGridY+1][pGridX]->m_position.y - 35);
		}
		m_currentDir = IDLE;
	}
	if (m_currentDir == UP && m_Grid->m_tileGrid[pGridY-1][pGridX]->getCurrentState() == WALL)
	{
		if (m_pos.x - m_Grid->m_tileGrid[pGridY-1][pGridX]->m_position.x >= 30)
		{
			m_sprite.setPosition(m_sprite.getPosition().x, m_Grid->m_tileGrid[pGridY - 1][pGridX]->m_position.y + 35);
		}
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
