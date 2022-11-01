//Written by Erwang Li & Xiangyu Liu
#include "ShapeParticle.h"

using namespace sf;

ShapeParticle::ShapeParticle(): shape(nullptr) {};

ShapeParticle::ShapeParticle(const Vector2f& position, const Vector2f& velocity, int lifespan)
:Particle(position, velocity, lifespan), shape(nullptr){
}

//Setters
void ShapeParticle::SetPosition(const Vector2f& pos) {
	shape->setPosition(pos);
	Particle::SetPosition(position);
}
void ShapeParticle::SetVelocity(const Vector2f& v) {
	velocity = v;
}
void ShapeParticle::SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
	color = Color(r, g, b, a);
	shape->setFillColor(color);
}
void ShapeParticle::SetHSVColor(int h, float s, float v) {
	this->HSVcolor = HSVColor(h, s, v);
}
void ShapeParticle::SetRotateSpeed(float rSpeed) {
	this->rotateSpeed = rSpeed;
}
void ShapeParticle::SetRotate(float angle) {
	shape->setRotation(angle);
}

//Getters
const Vector2f& ShapeParticle::GetPosition() const {
	return shape->getPosition();
}
const Vector2f& ShapeParticle::GetVelocity() const {
	return velocity;
}
const Shape* ShapeParticle::GetShape() const {
	return shape;
}
const Color& ShapeParticle::GetColor() const {
	return color;
}
const HSVColor& ShapeParticle::GetHSVColor() const {
	return HSVcolor;
}

//functions
void ShapeParticle::Sleep() {
	velocity = Vector2f(0.f, 0.f);
	shape->setPosition(0.f, 0.f);
	shape->setFillColor(Color::Transparent);
	alive = false;
	lifespan = 0;
}
void ShapeParticle::Reset(const Vector2f& position = Vector2f(0.f, 0.f), const Vector2f& velocity = Vector2f(0.f, 0.f), int lifespan =100) {
	shape->setFillColor(color);
	shape->setPosition(position);
	this->velocity = velocity;
	this->lifespan = lifespan;
	alive = true;
}

ShapeParticle::~ShapeParticle() {
	delete shape;
}