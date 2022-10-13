//Written by Erwang Li
#ifndef PARTICLE_EFFECT_H
#define PARTICLE_EFFECT_H
#include "Game.h"
#include "Particle.h"

class ParticleEffect
{
private:
	sf::Vector2i position;
	int lifespan;
	Particle* particles[20];
	boolean alive = false;
public:
	//Prototypes
	ParticleEffect(sf::Vector2i _position, int _lifespan);
	//creates a new particle for every element of the particles array
	void Emit();
	//adds a new particle at the specified index in the particles array (it should also randomize the particle velocity in some way)
	void AddParticle(int index);
	void update(sf::RenderWindow& window);
	void render(sf::RenderWindow& window);
	boolean isAlive();
	~ParticleEffect();
};

#endif

