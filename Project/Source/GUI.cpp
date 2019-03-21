/// <summary>
/// @mainpage 3rd year project - 2D platformer
/// @Author Sean Regan, Jamie Murphy
/// @Version 0.1
/// @brief GUI class to handle all buttons and widgets
/// </summary>

#include "../Header/GUI.h"

sf::Clock GUI::m_timeBetweenClicks = sf::Clock::Clock();

GUI::GUI()
{
	upKeyPrevious = false;
	downKeyPrevious = false;
	activatePause = true;
}

GUI::~GUI()
{
}

void GUI::addWidget(Widget * widget)
{
	m_elements.push_back(widget);
}

void GUI::update(int &index, int numOfItems)
{
	for each (Widget* i in m_elements)
	{
		i->update();	
	}

	if (m_elements[index]->getID() == "slider") //if element is a slider the these can be performed
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			m_elements[index]->decreaseValue();
			decreaseSliderValue(index);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			m_elements[index]->increaseValue();
			increaseSliderValue(index);
		}
	}


	//control schemes
	if (vertical)
	{
		verticalControls(index, numOfItems);
	}
	else if (horizontal)
	{
		horizontalControls(index, numOfItems);
	}
	else {
		vertAndHorControls(index, numOfItems);
	}

}

void GUI::draw(sf::RenderWindow & window)
{
	for each (Label* var in m_labels)
	{
		var->draw(window);
	}

	for each (Widget* i in m_elements)
	{
		i->draw(window);
	}
}

void GUI::moveDown(int &index, int numOfItems)
{
	if (index + 1 < numOfItems)
	{
		if (m_elements[index + 1]->isActive == false)
		{
			if (index + 2 < numOfItems)
			{
				m_elements[index]->loseFocus();
				index += 2;
				m_elements[index]->gainFocus();
			}
		}
		else
		{
			m_elements[index]->loseFocus();
			index++;
			m_elements[index]->gainFocus();
		}

	}
}

void GUI::moveUp(int &index)
{
	if (index - 1 >= 0)
	{
		if (m_elements[index - 1]->isActive == false)
		{
			if (index - 2 >= 0)
			{
				m_elements[index]->loseFocus();
				index -= 2;
				m_elements[index]->gainFocus();
			}
		}
		else
		{
			m_elements[index]->loseFocus();
			index--;
			m_elements[index]->gainFocus();
		}
	}
}

void GUI::activate(int &index)
{
	bool linked = false;

	if (m_elements[index]->getID() == "button")
	{
		try
		{
			m_elements[index]->Enter();
		}
		catch (std::bad_function_call)
		{
			std::cout << "Bad Function Call" << std::endl;
		}
	}
	else if (m_elements[index]->getID() == "checkbox")
	{
		if (m_elements[index]->checkActive() == false)
		{
			m_elements[index]->getActive();
			try
			{
				m_elements[index]->Enter();
			}
			catch (std::bad_function_call)
			{
				std::cout << "Bad Function Call" << std::endl;
			}
		}
		else {
			m_elements[index]->loseActive();
			try
			{
				m_elements[index]->Enter();
			}
			catch (std::bad_function_call)
			{
				std::cout << "Bad Function Call" << std::endl;
			}
		}
	}
	else
	{
		for (int i = 0; i < m_elements.size(); i++)
		{
			// if linked then deactivate
			if(m_elements[index]->checkTag() == m_elements[i]->checkTag() && m_elements[index]->getID() == m_elements[i]->getID())
			{
				m_elements[i]->loseActive();
				linked = true;
			}

			if (m_elements[index]->checkActive() == true && !linked)
			{
				m_elements[index]->loseActive();
			}
			else 
			{
				m_elements[index]->getActive();
				try 
				{
					m_elements[index]->Enter();
				}
				catch (std::bad_function_call)
				{
					std::cout << "Bad Function Call" << std::endl;
				}
			}
		}
	}
}

void GUI::addLabel(Label * label)
{
	m_labels.push_back(label);
}

void GUI::addButton(Button * button)
{
	m_elements.push_back(button);
}

void GUI::addSlider(Slider *slider)
{
	m_elements.push_back(slider);
}

void GUI::addRadioButton(RadioButton * radioButton)
{
	m_elements.push_back(radioButton);
}

void GUI::addCheckBox(CheckBox * checkBox)
{
	m_elements.push_back(checkBox);
}

//use callback functions of slider that are used to increase values
void GUI::increaseSliderValue(int &index)
{
	try {
		m_elements[index]->AdjustAdd();
		m_elements[index]->increaseValue();
	}
	catch (std::bad_function_call)
	{
		std::cout << "Bad Function Call" << std::endl;
	}
}

//use calback functions of slider that are used to decrease values
void GUI::decreaseSliderValue(int &index)
{
	try {
		m_elements[index]->AdjustMinus();
		m_elements[index]->decreaseValue();
	}
	catch (std::bad_function_call)
	{
		std::cout << "Bad Function Call" << std::endl;
	}
}

//vertical control scheme for dpad vertical use only
void GUI::verticalControls(int &index, int numOfItems)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !upKeyPrevious)
	{
		moveUp(index);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !downKeyPrevious)
	{
		moveDown(index, numOfItems);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && !activatePause)
	{
		if (m_elements[index]->getID() == "button") {

			m_timeBetweenClicks.getElapsedTime().asSeconds();
			if (m_timeBetweenClicks.getElapsedTime().asSeconds() > 1)
			{
				activate(index);
				m_timeBetweenClicks.restart();
			}
		}
		if (m_elements[index]->getID() == "radiobutton" || m_elements[index]->getID() == "checkbox")
		{
			activate(index);
		}

	}

	upKeyPrevious = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	downKeyPrevious = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
	activatePause = sf::Keyboard::isKeyPressed(sf::Keyboard::Return);
}

//horizontal control scheme for xbox controller, dpad horizontal use only
void GUI::horizontalControls(int & index, int numOfItems)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		moveUp(index);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		moveDown(index, numOfItems);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && !activatePause)
	{
		activate(index);
	}


	activatePause = sf::Keyboard::isKeyPressed(sf::Keyboard::Return);
}

//vertical and horizontal control scheme for xbox controller, dpad vertical and horizontal
void GUI::vertAndHorControls(int & index, int numOfItems)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !upKeyPrevious)
	{
		moveUp(index);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !downKeyPrevious)
	{
		moveDown(index, numOfItems);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && !activatePause)
	{
		activate(index);
	}

	upKeyPrevious = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	downKeyPrevious = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
	activatePause = sf::Keyboard::isKeyPressed(sf::Keyboard::Return);
}

//clear out all the elements 
void GUI::removeAllElements()
{
	m_elements.clear();
	m_labels.clear();
}