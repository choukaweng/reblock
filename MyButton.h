#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>


class MyButton
{
 public:
	sf::RectangleShape rect_;
	std:: string type;
	sf::Font font;
	sf::Text btnText;

	MyButton(  sf::Vector2f size,
               sf::Vector2f position
               , std::string text
              );
	void setFillColor(sf::Color col);
	void setOutlineThickness(float thickness);
	void setOutlineColor(sf::Color col);
	void setBtnText(std::string Text);

	void update();
	sf::Font& loadFont(const std::string& fontFilename = "resources/04b03.ttf");
	sf::Text& getText();
	sf::Shape& getShape();
};
