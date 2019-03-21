#pragma once

/// <summary>
/// @Player Class handling player acts and rendering 
/// @author Jamie Murphy and Sean Regan
/// @Version 0.1
/// @brief Player for the user to play as
/// </summary>

#include "Game.h"
#include "Bullet.h"

class Bullet;

class Player
{
public:
	Player();
	~Player();
	void update();
	void render(sf::RenderWindow & window);
	void applyForce(sf::Vector2f force);

	void checkCollision(sf::Vector2f size, sf::Vector2f pos);

private:
	float m_mass;
	float m_speed;
	float m_direction;
	sf::Vector2f m_size;
	sf::Vector2f m_pos;
	sf::Vector2f m_velocity;
	sf::Vector2f m_accel;
	sf::Vector2f m_gravity;
	sf::Vector2f m_jumpForce;
	sf::Vector2f m_moveForce;
	sf::Vector2f m_friction;
	sf::RectangleShape m_rect;
	sf::Time m_cumulativeTime;

	bool m_fall;
	bool m_jumping;
	bool m_movingLeft;
	bool m_movingRight;

	std::unique_ptr<Bullet> m_bullet;

	void jump();
	void moveLeft();
	void moveRight();
	void fire();
	//Player sprite
	sf::Texture m_Texture;//background texture
	sf::Sprite m_Sprite;//sprite for texture



};