#pragma once

/// <summary>
/// @mainpage 3rd year project - 2D platformer
/// @Author Sean Regan, Jamie Murphy
/// @Version 0.1
/// @brief Check box class to handle check boxs operations
/// </summary>
 
#include <SFML\Graphics.hpp>
#include "Label.h"
#include "Widget.h"

class CheckBox : public Widget {

public:
	CheckBox(std::string s, float x, float y);

	void gainFocus() override;	// Gain highlight
	void loseFocus() override;	// Lose highlight
	bool checkFocus() override;	// Check if object has focus

	void update() override;		// Update
	void draw(sf::RenderWindow &window) override;	// Draw
	void becomeActive();		// Turn on
	void loseActive();			// Turn off
	bool checkActive();			// Check if active

private:
	sf::RectangleShape m_icon;	// Box of the check box
	bool m_focus;				// Does it have focus
	bool m_isActive;			// Is the button turned on 
	sf::RectangleShape m_rect;	// Rectangle surrounding text
	sf::Font m_font;
	sf::Text m_text;

};