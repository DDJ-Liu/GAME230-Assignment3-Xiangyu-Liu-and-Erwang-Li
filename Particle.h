//Writen by Xiangyu Liu
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

class Particle
{
protected:
	//CircleShape particle;
	sf::Vector2f position;
	sf::Vector2f velocity;
	int lifespan;
	boolean alive = false;

public:
	Particle();
	Particle(const sf::Vector2f& position, const sf::Vector2f& velocity, int lifespan);

	virtual void Update(sf::RenderWindow& window) = 0;//movement of particle
	virtual void Render(sf::RenderWindow& window) = 0;

	//Setters
	virtual void SetPosition(const sf::Vector2f& pos);
	virtual void SetVelocity(const sf::Vector2f& v);
	virtual void SetLifespan(int life);
	virtual void SetAlive(bool a);
	
	// Getters
	virtual const sf::Vector2f& GetPosition() const;
	virtual const sf::Vector2f& GetVelocity() const;
	virtual const int GetLifespan() const;
	virtual const boolean isAlive() const;
	//float GetSize() const;

	//functions to reset and turn off shape
	virtual void Sleep() = 0;
	virtual void Reset(const sf::Vector2f& position, const sf::Vector2f& velocity, int lifespan) = 0;

	~Particle();
};

