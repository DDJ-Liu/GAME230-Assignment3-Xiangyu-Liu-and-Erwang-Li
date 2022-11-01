//Written by Xiangyu Liu
#pragma once
#include "ParticleEffect.h"
#include "CircleParticle.h"
class Snow :
    public ParticleEffect
{
protected:
	float width=50.f;
public:
	Snow();
	Snow(const sf::Vector2i& position, int lifespan, int particleNum, float width, bool loop);

	//update
	virtual void Update(sf::RenderWindow& window);
	//adds a new particle at the specified index in the particles array (tailor to effects)
	virtual void CreateParticle(int index);

	~Snow();
};

