#ifndef SCOREPICKUP_H
#define SCOREPICKUP_H

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

class ScorePickup {
public:
	ScorePickup();
	~ScorePickup();

	void update(float dt);
	void render(sf::RenderWindow & window);
	void setActive(bool active);
	bool getActive();
	void init(sf::Vector2f pos, sf::Texture & texture, sf::SoundBuffer & buffer);
	void setSize(int w, int h);
	void collison();
	float lerpFloat(float start, float end, float interpolate)
	{
		return (1.0f - interpolate) * start + (interpolate * end);
	}
	bool m_hit;
private:
	sf::Sprite m_sprite;
	bool m_active;
	
	float m_maxLerpTime;
	float m_currentTime;
	float m_currentPercent;
	float m_percentStep;
	sf::Vector2f m_startPosition;
	sf::Vector2f m_goalPosition;
	sf::Sound m_sound;
};

#endif // !SCOREPICKUP_H