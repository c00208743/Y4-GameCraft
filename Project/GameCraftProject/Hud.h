#ifndef HUD_H
#define HUD_H

#include <SFML\Graphics.hpp>

class Hud {
public:
	Hud();
	~Hud();

	void update(float dt);
	void render(sf::RenderWindow & window);

	void setHudSize(int w, int h);
	void setPosition(sf::Vector2f position);
	
	void setScore(const int score);
	void addScore(const int increment);
	void calcTextPositions();
private:
	sf::Font m_font;

	std::string m_scoreString = "Score: ";
	std::string m_timeString = "Time :";
	sf::Text m_scoreText;
	sf::Text m_timeText;

	sf::RectangleShape m_hudBackground;
	sf::Vector2f m_position;
	sf::Color m_fontColour;
	sf::Color m_backgroundColour;
	float m_timeSinceStart = 0.0f;
	int m_score;
};
#endif