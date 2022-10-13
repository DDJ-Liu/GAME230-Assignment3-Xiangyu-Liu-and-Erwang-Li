// SFML includes
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

// STL includes
#include <iostream>

// My Classes
#include "Game.h"
#include "Particle.h"
#include "ParticleEffect.h"

//Namespaces
using namespace sf;
using namespace gm;

int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML works!");

    Game g;
    while (window.isOpen())
    {
        g.handleInput(window);
        g.update(window);
        g.render(window);
    }

    return 0;
}