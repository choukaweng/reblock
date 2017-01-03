#include "MyButton.h"


// Box2D uses meters for simulation, so we need to set how many pixels representing one meter
// We prefer a 2^n value (e.g. 1,2,4,8,16,32,64 etc) because of reasons
// Why? Refer to Computer Graphics
static const float PIXEL_PER_METER = 64.0f;

MyButton :: MyButton(  sf::Vector2f size,
               sf::Vector2f position,
               std::string text
              )
{
	rect_ = sf::RectangleShape(size);
	rect_.setOrigin(sf::Vector2f(size.x/2,size.y/2));
	rect_.setFillColor(sf::Color(255, 255, 255, 255));
	rect_.setOutlineThickness(1);
	rect_.setOutlineColor(sf::Color::Black);
    rect_.setPosition(position);

    font = loadFont();
    btnText.setFont(font);
    btnText.setPosition(position) ;
    btnText.setString("LEVEL ONE");
    btnText.setColor(sf::Color::Black);

}

sf::Font& MyButton::loadFont(const std::string& fontFilename)
{
   sf::Font myFont;
   myFont.loadFromFile(fontFilename);
   return myFont;
}

void MyButton::setFillColor(sf::Color col)
{
	rect_.setFillColor(col);
}

void MyButton::setOutlineThickness(float thickness)
{
	rect_.setOutlineThickness(thickness);
}

void MyButton::setOutlineColor(sf::Color col)
{
	rect_.setOutlineColor(col);
}

void MyButton::setBtnText(std::string Text)
{
    btnText.setString(Text);
}

void MyButton::update()
{
	// Box2D uses radians for rotation, SFML uses degree

}

sf::Text& MyButton::getText()
{
    return btnText;
}

sf::Shape& MyButton::getShape()
{
	return rect_;
}
