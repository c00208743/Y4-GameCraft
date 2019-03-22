#include "Ai.h"
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

Ai::Ai()
{
	m_pos = sf::Vector2f(200, 200);
	velocity = sf::Vector2f(0, 0);

	if (!m_Txt.loadFromFile("./assets/aiImg.png"))
	{
		std::cout << "Error loading player Image";
	}
	m_sprite.setTexture(m_Txt);
	m_sprite.setPosition(m_pos);
	srand(time(0));
}

Ai::~Ai()
{
}

void Ai::update()
{
	move();
	collision();
	setDirection();
	m_sprite.setPosition(m_pos);
	timer++;
}

void Ai::setDirection()
{
	//set 
		//m_currentDir = RIGHT;

	if (timer % 200 == 0) {
		//choose a direction
		r = (rand() % 4) + 1;
		if (r == 1) {
			m_currentDir = d_LEFT;
			std::cout << "L"<<std::endl;
		}
		if (r == 2) {
			m_currentDir = d_RIGHT;
			std::cout << "R" << std::endl;
		}
		if (r == 3) {
			m_currentDir = d_UP;
			std::cout << "U" << std::endl;
		}
		if (r == 4) {
			m_currentDir = d_DOWN;
			std::cout << "D" << std::endl;
		}
	}
	// should change direction on collison -- set timer to 0
}

void Ai::move()
{


	if (m_currentDir == d_LEFT)
	{
		velocity.x = -10;
		velocity.y = 0;
		m_pos.x +=  velocity.x;
		m_pos.y +=  velocity.y;
	}
	 if (m_currentDir == d_RIGHT)
	{
		velocity.x = 10;
		velocity.y = 0;
		m_pos.x +=  velocity.x;
		m_pos.y +=  velocity.y;
	}
	if (m_currentDir == d_UP)
	{
		velocity.x = 0;
		velocity.y = -10;
		m_pos.x +=  velocity.x;
		m_pos.y +=  velocity.y;
	}
	if (m_currentDir == d_DOWN)
	{
		velocity.x = 0;
		velocity.y = 10;
		m_pos.x +=  velocity.x;
		m_pos.y +=  velocity.y;
	}
}

void Ai::collision()
{
	if (m_pos.x >= 750 && velocity.x > 0)
	{
		m_pos.x = 740;
		m_currentDir = d_IDLE;
	}
	else if (m_pos.x <= 40 && velocity.x < 0)
	{
		m_pos.x = 0;
		m_currentDir = d_IDLE;
	}

	if (m_pos.y >= 550 && velocity.y > 0)
	{
		m_pos.y = 540;
		m_currentDir = d_IDLE;
	}
	else if (m_pos.y <= 40 && velocity.y < 0)
	{
		m_pos.y = 0;
		m_currentDir = d_IDLE;
	}
}

sf::Vector2f Ai::getPos()
{
	return m_pos;
}

void Ai::render(sf::RenderWindow &window)
{
	window.draw(m_sprite);

}
