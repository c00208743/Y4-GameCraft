#pragma once

/// <summary>
/// @mainpage 3rd year project - 2D platformer
/// @Author Sean Regan, Jamie Murphy
/// @Version 0.1
/// @brief Slider class to handle slider operations
/// </summary>

#include<SFML\Graphics.hpp>
#include"Label.h"
#include"Widget.h"

class Slider : public Widget {

public:
	Slider(float x, float y, float &value, std::string s);

	void gainFocus() override;	// Gain highlight
	void loseFocus() override;	// Lose highlight
	bool checkFocus()override;	// Check for focus

	void update()override;		// Update loop
	void draw(sf::RenderWindow &window)override;	// Draw loop
	int getValue();				// Get sliders value
	void increaseValue();		// Increase rect length
	void decreaseValue();		// Decrease it

private:

	sf::RectangleShape m_innerRect;		// Inner rectangle

	float m_rectX = 180;
	float m_rectY = 10;
	float m_val;				// Slider value

	sf::Font m_font;
	sf::Text m_text;

};