#pragma once

/// <summary>
/// @mainpage 3rd year project - 2D platformer
/// @Author Sean Regan, Jamie Murphy
/// @Version 0.1
/// @brief Label class to handle labels for widgets
/// </summary>
 
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Widget.h"

class Label : public Widget
{
public:
	Label(std::string s, float x, float y);	// Constructor
	Label(std::string s, float x, float y, std::string font);	// Constructor
	void draw(sf::RenderWindow &window);	// Draw loop
	void update();							// Update loop
	void setUnderLined();					// Make label underlined
	void updateText(std::string s);			// Change the text of the label
	void changeTextSize(int size);			// Change size of the label
	void changeFont(sf::Font font);			// Change the text font


protected:
	sf::Vector2f m_pos;
	sf::Text m_text;
	sf::Font m_font;
	int m_fontSize;
};