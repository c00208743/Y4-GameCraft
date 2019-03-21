#pragma once

/// <summary>
/// @mainpage 3rd year project - 2D platformer
/// @Author Sean Regan, Jamie Murphy
/// @Version 0.1
/// @brief GUI class to handle all buttons and widgets
/// </summary>
 
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Widget.h"
#include"Label.h"
#include"CheckBox.h"
#include"Button.h"
#include"RadioButton.h"
#include"Slider.h"


class GUI
{
public:
	GUI();
	~GUI();
	void update(int &index, int numOfItems);	// Update loop
	void draw(sf::RenderWindow &window);		// Draw loop
	void moveDown(int &index, int numOfItems);	// Move down to the next GUI object
	void moveUp(int &index);					// Move up to the previous GUI object
	void activate(int &index);					// Activate current GUI objects function
	void addWidget(Widget *widget);				// Add a widget
	void addLabel(Label *label);				// Add a label
	void addButton(Button *button);				// Add a button
	void addSlider(Slider *slider);				// Add a slider
	void addRadioButton(RadioButton *radioButton);	// Add a radio button
	void addCheckBox(CheckBox *checkBox);		// Add a check box
	void increaseSliderValue(int &index); //increase the value of a slider
	void decreaseSliderValue(int &index); //decrease
	void verticalControls(int &index, int numOfItems); //controls designed to be used dpad vertically only
	void horizontalControls(int &index, int numOfItems); //left and right only
	void vertAndHorControls(int &index, int numOfItems); //mixture
	void removeAllElements(); //clear the containers
	bool vertical; //when true use vert controls
	bool horizontal; //use horizontal
	bool both; //use mixture
	bool upKeyPrevious;
	bool downKeyPrevious;
	bool activatePause;							// Prevents activate begin called straight away.
	static sf::Clock m_timeBetweenClicks;

protected:
	std::vector<Widget *> m_elements;			// Container to hold widgets
	std::vector<Label *>m_labels; //holds all labels, labels can be also stored in m_elements

};