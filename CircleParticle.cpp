//Written by Erwang Li
#include "CircleParticle.h"

using namespace sf;

//Constructor
CircleParticle::CircleParticle() : ShapeParticle() {
	shape = new CircleShape();
	shape->setFillColor(color);
}
CircleParticle::CircleParticle(const Vector2f& position, const Vector2f& velocity, float size, int lifespan) 
: ShapeParticle(position, velocity, lifespan) {
	shape = new CircleShape(size);
	shape->setFillColor(color);
	shape->setPosition(position);
}

//update and render functions
void CircleParticle::Update(sf::RenderWindow& window) {
	Particle::Update(window);
	//Move particle based on velocity
	//shape->setPosition(Vector2f(GetPosition().x + GetVelocity().x, GetPosition().y + GetVelocity().y));
}
void CircleParticle::Render(sf::RenderWindow& window) {
	window.draw(*dynamic_cast<CircleShape*>(shape));
}

//Setter for size
void CircleParticle::SetRadius(float radius) {
	dynamic_cast<CircleShape*>(shape)->setRadius(radius);
}
//Getter for size
const float CircleParticle::GetRadius() const {
	return dynamic_cast<CircleShape*>(shape)->getRadius();
}

//functions to reset and turn off shape had been implemented

//Destructor
CircleParticle::~CircleParticle() {
	delete shape;
}