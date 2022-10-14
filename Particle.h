//Writen by Xiangyu Liu
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

using namespace sf;

class Particle
{
private:
	CircleShape particle;
	Vector2f velocity;
	int lifespan;
	boolean alive = false;

public:
	Particle(float vx , float vy, float size, int life, sf::Color c);
	~Particle();
	void Update(RenderWindow& window);//movement of particle
	void Render(RenderWindow& window);
	void SetPosition(Vector2f pos);
	Vector2f GetPosition();
	float GetSize();
	boolean isAlive();

};

