#ifndef MYCIRCLE_H
#define MYCIRCLE_H
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>


class MyCircle
{
 public:
	sf::CircleShape circle;
	b2Body* body_;
	b2BodyDef bodyDef_;
	b2CircleShape bodyShape_;
	b2FixtureDef bodyFixtureDef_;
	std:: string type;

	MyCircle(b2World& world,
               float radius,
               sf::Vector2f position,
               float rotation = 0,
               bool isDynamic = true
              );
	void setFillColor(sf::Color col);
	void setOutlineThickness(float thickness);
	void setOutlineColor(sf::Color col);
	void update();
	sf::Shape& getShape();
};


#endif // MYCIRCLE_H
