#ifndef SHAPE_PARTICLE_H
#define SHAPE_PARTICLE_H
#include "Particle.h"
#include "HSVColor.h"

class ShapeParticle :
    public Particle
{
protected:
    // A shape pointer for the particle
    sf::Shape* shape;
    sf::Color color = sf::Color::White;
    HSVColor HSVcolor = HSVColor(0, 1.f, 1.f);
public:

    //Constructor
    ShapeParticle();
    ShapeParticle(const sf::Vector2f& position, const sf::Vector2f& velocity, int lifespan);

    //pure virtual functions
    virtual void Update(sf::RenderWindow& window) = 0;
    virtual void Render(sf::RenderWindow& window) = 0;

    //Setters
    virtual void SetPosition(const sf::Vector2f& pos);
    virtual void SetVelocity(const sf::Vector2f& v);
    virtual void SetColor(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, sf::Uint8 a);
    virtual void SetHSVColor(int h, float s, float v);

    //Getters
    virtual const sf::Vector2f& GetPosition() const;
    virtual const sf::Vector2f& GetVelocity() const;
    virtual const sf::Shape* GetShape() const;
    virtual const sf::Color& GetColor() const;
    virtual const HSVColor& GetHSVColor() const;

    //functions to reset and turn off shape
    virtual void Sleep();
    virtual void Reset(const sf::Vector2f& position, const sf::Vector2f& velocity, int lifespan);

    ~ShapeParticle();
};
#endif

