#include "MyCircle.h"

// Box2D uses meters for simulation, so we need to set how many pixels representing one meter
// We prefer a 2^n value (e.g. 1,2,4,8,16,32,64 etc) because of reasons
// Why? Refer to Computer Graphics
static const float PIXEL_PER_METER = 64.0f;

MyCircle::MyCircle(b2World& world,
                         float radius,
                         sf::Vector2f position,
						 float rotation,
                         bool isDynamic
                         )
{
	circle = sf::CircleShape(radius);
	circle.setOrigin(16,16);
	circle.setFillColor(sf::Color(255, 255, 255, 255));
	circle.setOutlineThickness(1);
	circle.setOutlineColor(sf::Color::Black);


	bodyDef_.position = b2Vec2(position.x/PIXEL_PER_METER, position.y/PIXEL_PER_METER);
    bodyDef_.angle = rotation;

	if (isDynamic)
   {
      bodyDef_.type = b2_dynamicBody;
   }
   else
   {
      bodyDef_.type = b2_staticBody;
   }
    bodyShape_.m_radius = radius/PIXEL_PER_METER;

	bodyFixtureDef_.shape = &bodyShape_;
	bodyFixtureDef_.density = 0.3f;
	bodyFixtureDef_.friction = 0.0f;

	body_ = world.CreateBody(&bodyDef_);
	body_->CreateFixture(&bodyFixtureDef_);
}

void MyCircle::setFillColor(sf::Color col)
{
	circle.setFillColor(col);
}

void MyCircle::setOutlineThickness(float thickness)
{
	circle.setOutlineThickness(thickness);
}

void MyCircle::setOutlineColor(sf::Color col)
{
	circle.setOutlineColor(col);
}


void MyCircle::update()
{
	// Box2D uses radians for rotation, SFML uses degree
    circle.setRotation( body_->GetAngle() * 180/b2_pi);
    circle.setPosition( body_->GetPosition().x*PIXEL_PER_METER, body_->GetPosition().y*PIXEL_PER_METER);
}

void MyCircle::destroy(b2World &world)
{
    world.DestroyBody(body_);
}

sf::Shape& MyCircle::getShape()
{
	return circle;
}
