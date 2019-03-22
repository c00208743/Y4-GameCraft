#ifndef SCOREPICKUP_H
#define SCOREPICKUP_H

#include <SFML\Graphics.hpp>

class ScorePickup {
public:
	ScorePickup();
	~ScorePickup();

	void update(float dt);
	void render(sf::RenderWindow & window);
	void setActive(bool active);
	void init(sf::Vector2f pos, sf::Texture & texture);
	void setSize(int w, int h);
private:
	sf::Sprite m_sprite;
	bool m_active;
};

#endif // !SCOREPICKUP_H