//Written by Xiangyu Liu
#include "Particle.h"

Particle::Particle(float vx = 0, float vy = 0, float size = 10, int life = 100, sf::Color c = Color::Green) {
	particle = CircleShape(size);
	particle.setPosition(Vector2f(0, 0));
	velocity = Vector2f(vx, vy);
	lifespan = life;
	alive = true;
}
Particle::~Particle() {
	alive = false;
}
//movement of particles
void Particle::Update(RenderWindow& window) {
	particle.setPosition(particle.getPosition() + velocity);
	lifespan--;
	if (lifespan<=0) {
		alive = false;
		particle.setFillColor(Color::Transparent);
	}
}

void Particle::Render(RenderWindow& window) {
	window.draw(particle);
}

Vector2f Particle::GetPosition() {
	return particle.getPosition();
}

float Particle::GetSize() {
	return particle.getRadius();
}

boolean Particle::isAlive() {
	return alive;
}

void Particle::SetPosition(Vector2f pos) {
	particle.setPosition(pos);
	return;
}
