#pragma once

/// <summary>
/// @mainpage 3rd year project - 2D platformer
/// @Author Sean Regan, Jamie Murphy
/// @Version 0.1
/// @brief Radio button class to handle radio button operations
/// </summary>
 

#include<SFML\Graphics.hpp>
#include"Label.h"
#include"Widget.h"

class RadioButton : public Widget {

public:
	RadioButton(std::string s, float x, float y, std::string tag);

	void gainFocus() override;	// Gain highlight
	void loseFocus() override;	// Lose highlight
	bool checkFocus()override;	// Check for focus

	void update()override;		// Update
	void draw(sf::RenderWindow &window)override;	//Draw
	void becomeActive();		// Turn radio button on
	void loseActive();			// Turn it off
	bool checkActive();			// Check  if its active or not





private:
	sf::CircleShape m_icon;		// Circle next to font
	bool m_focus;				// Does it have focus
	bool m_isActive;			// Is the button turned on
	sf::RectangleShape m_rect;	// Rectangle surrounding text
	sf::Font m_font;
	sf::Text m_text;

};