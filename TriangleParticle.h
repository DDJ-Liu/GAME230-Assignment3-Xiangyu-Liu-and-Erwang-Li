//Written by Xiangyu Liu
#pragma once
#include "ShapeParticle.h"
#include<cstdlib>
#include<ctime>
class TriangleParticle :
    public ShapeParticle
{
public:
    enum shapeType{equilateral,right,randTri};
    shapeType triType= randTri;

    //Constructor
    TriangleParticle();
    TriangleParticle(const sf::Vector2f& position, const sf::Vector2f& velocity, float size, int lifespan,shapeType type,float rotateSpeed);

    //update and render functions
    virtual void Update(sf::RenderWindow& window);
    virtual void Render(sf::RenderWindow& window);

    //Setters are already implemented but size
    virtual void SetScale(float scale);
    //Getters are already implemented but size
    virtual const float GetScale() const;

    //functions to reset and turn off shape had been implemented
    //virtual void Sleep();
    //virtual void Reset(const sf::Vector2f& position, const sf::Vector2f& velocity, int lifespan);

    ~TriangleParticle();

    //random function
    float Randf(float min, float max);
};

