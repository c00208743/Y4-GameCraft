#pragma once

/// <summary>
/// @mainpage 3rd year project - 2D platformer
/// @Author Sean Regan, Jamie Murphy
/// @Version 0.1
/// @brief Widget class to handle gui objects
/// </summary>

#include <SFML\Graphics.hpp>
#include <functional>

class Widget
{
public:
	Widget();
	~Widget();
	virtual void gainFocus();	// element becomes the one currently selected
	virtual void loseFocus();	// element stops the one currently selected
	virtual bool checkFocus();	// Checks if element is the one currently selected
	virtual void update();		// Update loop
	virtual void getActive();	
	virtual void loseActive();
	virtual bool checkActive();	// Checks if element is active
	virtual void draw(sf::RenderWindow & window);	// Draw loop
	std::string getID();		// Check the UI elements ID
	virtual void setRectColour(sf::Color colour);	// Changes the colour of the rectangle
	void activateCallBack();
	std::string checkTag();		//Return tag
	virtual void changeTextSize(int size);			// Change font size
	typedef std::function<void()> Callback;
	Callback Enter;
	Callback AdjustAdd;
	Callback AdjustMinus; //callback functions
	bool isActive;				// is element active
	virtual void increaseValue();
	virtual void decreaseValue(); //for sliders

protected:
	sf::RectangleShape m_rect;	// Rectangle surrounding the element
	bool m_focus;				// Bool to tell if element has focus
	std::string m_id;			// id of the element
	std::string m_tag;			// tag of element

};