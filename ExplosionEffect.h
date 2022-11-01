//Written by Xiangyu Liu
#pragma once
#include "ParticleEffect.h"
#include "TriangleParticle.h"

class ExplosionEffect :
    public ParticleEffect
{
protected:
	float intensity=5.f;
public:
	ExplosionEffect();
	ExplosionEffect(const sf::Vector2i& position, int lifespan, int particleNum, float intensity, bool loop);

	//update
	virtual void Update(sf::RenderWindow& window);
	//adds a new particle at the specified index in the particles array (tailor to effects)
	virtual void CreateParticle(int index);

	~ExplosionEffect();
};

