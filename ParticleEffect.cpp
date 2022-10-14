//Written by Erwang Li
#include "ParticleEffect.h"


ParticleEffect::ParticleEffect(sf::Vector2i _position, int _lifespan, int _particleNum = 20) {
	position = _position;
	lifespan = _lifespan;
	alive = true;
	particleNum = _particleNum;
	particles = new Particle*[particleNum];
}
//creates a new particle for every element of the particles array
void ParticleEffect::Emit() {
	for (int i = 0; i < particleNum; i++) {
		AddParticle(i);
	}
}
//adds a new particle at the specified index in the particles array (it should also randomize the particle velocity in some way)
void ParticleEffect::AddParticle(int index) {
	Particle* particle = new Particle(gm::Rand(-5, 5), gm::Rand(-5, 5), float(gm::Rand(2, 10)), gm::Rand(120, 600), sf::Color::White);
	(* particle).SetPosition(Vector2f(float(position.x)- particle->GetSize(), float(position.y)- particle->GetSize()));
	particles[index] = particle;
}
void ParticleEffect::update(sf::RenderWindow& window) {
	for (int i = 0; i < particleNum; i++) {
		particles[i]->Update(window);
		//looping functionality
		if (!particles[i]->isAlive()) {
			delete particles[i];
			AddParticle(i);
		}
	}
	lifespan--;
	if (lifespan <= 0) {
		alive = false;
	}
}
void ParticleEffect::render(sf::RenderWindow& window) {
	for (int i = 0; i < particleNum; i++) {
		particles[i]->Render(window);
	}
}

boolean ParticleEffect::isAlive() {
	return alive;
}

ParticleEffect::~ParticleEffect() {
	for (int i = 0; i < 20; i++) {
		delete particles[i];
	}
}