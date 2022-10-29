//Written by Xiangyu Liu
#include "Particle.h"

using namespace sf;

//Constructor
Particle::Particle(): lifespan(0) {};

Particle::Particle(const Vector2f& position, const Vector2f& velocity, int lifespan) 
: position(position), velocity(velocity), lifespan(lifespan), alive(true) {
}

//Destructor
Particle::~Particle() {

}

//movement of particles
void Particle::Update(RenderWindow& window) {
	//particle.setPosition(particle.getPosition() + Vector2f(velocity.x / 10,velocity.y/10));
	if(alive)
		lifespan--;
	if (alive && lifespan<=0) {
		Sleep();
	}
}

//Setter
void Particle::SetPosition(const sf::Vector2f& pos) {
	position = pos;
}
void Particle::SetVelocity(const sf::Vector2f& v) {
	velocity = v;
}

void Particle::SetLifespan(int life) {
	this->lifespan = life;
};
void Particle::SetAlive(bool a) {
	this->alive = a;
};

// Getters
const Vector2f& Particle::GetPosition() const {
	return position;
}
const Vector2f& Particle::GetVelocity() const {
	return velocity;
}
const int Particle::GetLifespan() const {
	return lifespan;
}
const boolean Particle::isAlive() const{
	return alive;
}
