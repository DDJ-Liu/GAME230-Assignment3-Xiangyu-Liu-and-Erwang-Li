//modified by Erwang Li & Xiangyu Liu
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

namespace gm {
	class Game {
	private:
		
	public:
		//Prototypes
		Game();
		void handleInput(sf::RenderWindow& window);
		void update(sf::RenderWindow& window);
		void render(sf::RenderWindow& window);
		~Game();
	};

	//Help functions
	int Rand(int min, int max);
	float Randf(float min, float max);
	sf::Color hsv(int hue, float sat, float val);
	

}

#endif
