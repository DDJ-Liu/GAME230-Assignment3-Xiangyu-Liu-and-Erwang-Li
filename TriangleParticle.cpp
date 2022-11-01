//Written by Xiangyu Liu
#include "TriangleParticle.h"

using namespace sf;

//Constructor
TriangleParticle::TriangleParticle() : ShapeParticle() {
	shape = new ConvexShape(3);
	shape->setFillColor(color);
}

TriangleParticle::TriangleParticle(const sf::Vector2f& position, const sf::Vector2f& velocity, float size, int lifespan, shapeType type, float rotateSpeed):ShapeParticle(position,velocity,lifespan) {
	shape = new ConvexShape(3);
	shape->setFillColor(color);
	shape->setPosition(position);
	this->rotateSpeed = rotateSpeed;
	switch (type)
	{
	case TriangleParticle::equilateral:
		dynamic_cast<ConvexShape*>(shape)->setPoint(0, Vector2f(0.f, 0.f));
		dynamic_cast<ConvexShape*>(shape)->setPoint(1, Vector2f(1.f, 0.f));
		dynamic_cast<ConvexShape*>(shape)->setPoint(2, Vector2f(.5f, .866f));
		break;
	case TriangleParticle::right:
		dynamic_cast<ConvexShape*>(shape)->setPoint(0, Vector2f(0.f, 0.f));
		dynamic_cast<ConvexShape*>(shape)->setPoint(1, Vector2f(1.f, 0.f));
		dynamic_cast<ConvexShape*>(shape)->setPoint(2, Vector2f(0.f, 1.f));
		break;
	case TriangleParticle::randTri:
		dynamic_cast<ConvexShape*>(shape)->setPoint(0, Vector2f(Randf(-1.f, 1.f), Randf(-1.f, 1.f)));
		dynamic_cast<ConvexShape*>(shape)->setPoint(1, Vector2f(Randf(-1.f, 1.f), Randf(-1.f, 1.f)));
		dynamic_cast<ConvexShape*>(shape)->setPoint(2, Vector2f(Randf(-1.f, 1.f), Randf(-1.f, 1.f)));
		break;
	default:
		break;
	}
	shape->setScale(size, size);
}

//update and render functions
void TriangleParticle::Update(sf::RenderWindow& window) {
	Particle::Update(window);
	shape->setRotation(shape->getRotation() + rotateSpeed);
}
void TriangleParticle::Render(sf::RenderWindow& window) {
	if (isAlive()) {
		window.draw(*dynamic_cast<ConvexShape*>(shape));
	}
}

//Setters are already implemented but size
void TriangleParticle::SetScale(float scale) {
	dynamic_cast<ConvexShape*>(shape)->setScale(scale,scale);
}
//Getters are already implemented but size
const float TriangleParticle::GetScale() const {
	return dynamic_cast<ConvexShape*>(shape)->getScale().x;
}

//functions to reset and turn off shape had been implemented
//virtual void Sleep();
//virtual void Reset(const sf::Vector2f& position, const sf::Vector2f& velocity, int lifespan);

TriangleParticle::~TriangleParticle() {
	delete shape;
}

float TriangleParticle::Randf(float min, float max) {
	static bool setup = true;
	if (setup)
	{
		srand(time(NULL)); //seeding
		setup = false;
	}
	return (min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min))));
}


