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
using namespace std;

int main()
{
    RenderWindow window(VideoMode(800, 600), "My Particle Generator");
    window.setFramerateLimit(60);

    cout << "Right Click to generate particles." << endl << endl;
    cout << "Press Key to change particle types :" << endl;
    cout << "    " << '"' << "Num1" << '"' << " - Colorful Bubbles(Looping)" << endl;
    cout << "    " << '"' << "Num2" << '"' << " - Explosion(Non-Looping)" << endl;
    cout << "    " << '"' << "Num3" << '"' << " - Snow(Looping)" << endl;

    Game g;
    while (window.isOpen())
    {
        g.handleInput(window);
        g.update(window);
        g.render(window);
    }

    return 0;
}