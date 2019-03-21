#pragma once

/// <summary>
/// @mainpage 3rd year project - 2D platformer
/// @Author Sean Regan, Jamie Murphy
/// @Version 0.1
/// @brief Button class for all buttons 
/// </summary>

#include <SFML\Graphics.hpp>
#include "Label.h"
#include "Widget.h"
#include <functional>

class Button : public Widget
{
public:
	Button(std::string s, float x, float y);
	Button(std::string s, float x, float y, std::string font);
	Button(std::string s, float x, float y, int size);
	Button(std::string s, float x, float y, sf::Color color, std::string tag);
	~Button();
	void gainFocus() override;	// make button the current highlighted element
	void loseFocus() override;	// lose highlight
	bool checkFocus() override; // check if highlighted
	void update() override;		// update loop
	void draw(sf::RenderWindow &window) override;	// Draw loop
	void setRectColour(sf::Color colour);			// Set the rect colour of button
	void changeTextSize(int size);

protected:
	sf::RectangleShape m_rect;	// Rectangle that will surround text
	bool m_hasFocus;			
	sf::Font m_font;			
	sf::Text m_text;
};