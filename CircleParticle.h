//Written by Erwang Li
#ifndef CIRCLE_PARTICLE_H
#define CIRCLE_PARTICLE_H
#include "ShapeParticle.h"

class CircleParticle :
    public ShapeParticle
{
public:
    //Constructor
    CircleParticle();
    CircleParticle(const sf::Vector2f& position, const sf::Vector2f& velocity, float size, int lifespan);

    //update and render functions
    virtual void Update(sf::RenderWindow& window);
    virtual void Render(sf::RenderWindow& window);

    //Setters are already implemented but size
    virtual void SetRadius(float radius) ;
    //Getters are already implemented but size
    virtual const float GetRadius() const;

    //functions to reset and turn off shape had been implemented
    //virtual void Sleep();
    //virtual void Reset(const sf::Vector2f& position, const sf::Vector2f& velocity, int lifespan);

    ~CircleParticle();
};
#endif
