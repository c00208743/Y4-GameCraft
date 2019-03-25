#include "Player.h"

Player::Player(Grid &Grid):
	m_Grid(&Grid),
	m_pool(40)
{
	m_pool.init();
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
	m_pool.shutdown();
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_currentDir ==IDLE
		&& m_Grid->m_tileGrid[pGridY - 1][pGridX]->getCurrentState() != WALL)
	{
		m_currentDir = UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_currentDir == IDLE
		&& m_Grid->m_tileGrid[pGridY +1 ][pGridX]->getCurrentState() != WALL)
	{
		m_currentDir = DOWN;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_currentDir == IDLE
		&& m_Grid->m_tileGrid[pGridY][pGridX -1 ]->getCurrentState() != WALL)
	{
		m_currentDir = LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_currentDir == IDLE
		&& m_Grid->m_tileGrid[pGridY][pGridX +1]->getCurrentState() != WALL)
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

void lerpScore(ScorePickup * pickup)
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	bool done = false;
	pickup->collison();
	while (!done)
	{
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			if (pickup->getActive()) {
				pickup->update(timePerFrame.asSeconds()); // 60 fps
			}
			else {
				done = true;
				break;
			}
		}
	}
	std::cout << "Thread finished" << std::endl;
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
	if (m_Grid->m_tileGrid[pGridY][pGridX]->getCurrentState() == GOAL && m_Grid->goalReached == false)
	{
		m_pool.shutdown();
		m_pool.init();
		m_Grid->goalReached = true;
		m_Grid->loadNextLevel();
		m_pos = sf::Vector2f(75, 125);
		m_sprite.setPosition(m_pos);
		
	}
	if (m_Grid->m_tileGrid[pGridY][pGridX]->getCurrentState() == NONE) {
		std::pair<int, int> pPos(pGridY, pGridX);
		if (m_Grid->m_scorePickups[pPos].getActive() && !m_Grid->m_scorePickups[pPos].m_hit) {
			m_score++;
			m_pool.submit(lerpScore, &m_Grid->m_scorePickups[pPos]);
		}
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
