//Written by Erwang Li
#ifndef PARTICLE_EFFECT_H
#define PARTICLE_EFFECT_H
#include "Game.h"
#include "Particle.h"
#include <vector>

class ParticleEffect
{
protected:
	sf::Vector2f position;
	int lifespan;
	//Particle** particles;

	std::vector<Particle*> particles;
	boolean alive = false;
	int particleNum;
	bool loop = false;

public:
	//Prototypes
	ParticleEffect();
	ParticleEffect(const sf::Vector2f &position, int lifespan, int particleNum, bool loop);

	//update & render
	virtual void Update(sf::RenderWindow& window);
	virtual void Render(sf::RenderWindow& window);

	//adds a new particle at the specified index in the particles array (tailor to effects)
	virtual void CreateParticle(int index) = 0;
	//Creates a new particle for every element of the particles array
	virtual void Emit();

	virtual boolean isAlive() const;
	~ParticleEffect();
};


#endif

