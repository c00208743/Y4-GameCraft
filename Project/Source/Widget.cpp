#include "../Header/Widget.h"

Widget::Widget()
{
	isActive = true;
}

Widget::~Widget()
{

}

//widget get focus
void Widget::gainFocus()
{
	m_focus = true;
}
//widget lose focus
void Widget::loseFocus()
{
	m_focus = false;
}
//check focus
bool Widget::checkFocus()
{
	return m_focus;
}
//update loop
void Widget::update()
{


}

//draw loop
void Widget::draw(sf::RenderWindow &window)
{


}

//make widget active 
void Widget::getActive()
{
}

//lose widget active
void Widget::loseActive()
{
}

//check if widget is active
bool Widget::checkActive()
{
	return m_focus;
}

//return id of the widget
std::string Widget::getID()
{
	return m_id;
}

//activate callback function
void Widget::activateCallBack()
{
	Enter();
}

//check the tag of the widget
std::string Widget::checkTag()
{
	return m_tag;
}


//set the widgets rectangle color
void Widget::setRectColour(sf::Color colour)
{
}

//change the widgets text size
void Widget::changeTextSize(int size)
{
}

//increase the value of the widget
void Widget::increaseValue()
{

}

//decrease the widgets value
void Widget::decreaseValue()
{

}