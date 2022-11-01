//Written by Erwang Li
#ifndef COLORFUL_CIRCLES_EFFECT_H
#define COLORFUL_CIRCLES_EFFECT_H
#include "ParticleEffect.h"

class ColorfulCirclesEffect :
    public ParticleEffect
{
public:
	ColorfulCirclesEffect();
	ColorfulCirclesEffect(const sf::Vector2i& position, int lifespan, int particleNum, bool loop);

	//update
	virtual void Update(sf::RenderWindow& window);
	//adds a new particle at the specified index in the particles array (tailor to effects)
	virtual void CreateParticle(int index);

	~ColorfulCirclesEffect();
};
#endif
