#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>


class MyRectangle
{
 public:
	sf::RectangleShape rect_;
	b2Body* body_;
	b2BodyDef bodyDef_;
	b2PolygonShape bodyShape_;
	b2FixtureDef bodyFixtureDef_;
	std:: string type;

	MyRectangle(b2World& world,
               sf::Vector2f size,
               sf::Vector2f position,
               float rotation = 0,
               bool isDynamic = true
              );
	void setFillColor(sf::Color col);
	void setOutlineThickness(float thickness);
	void setOutlineColor(sf::Color col);
	void setRotation(float rotation);
	void update();
	void destroy(b2World &world);
	sf::Shape& getShape();
};
