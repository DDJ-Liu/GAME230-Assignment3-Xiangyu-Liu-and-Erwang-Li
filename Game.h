//modified by Erwang Li
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Particle.h"
#include "ParticleEffect.h"


namespace gm {
	class Game {
	public:
		//Prototypes
		Game();
		void handleInput(sf::RenderWindow& window);
		void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		~Game();
	};

	//Tool Random function
	int Rand(int min, int max);
}

#endif
