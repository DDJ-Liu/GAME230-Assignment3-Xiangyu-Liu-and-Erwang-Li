//modified by Erwang Li
#include "Game.h"

using namespace gm;

//Global variable
std::vector<ParticleEffect*> particleStack;

Game::Game() {

}

void Game::handleInput(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
		//LMB
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Button::Left) {
				ParticleEffect* currentParticleEffect = new ParticleEffect(sf::Mouse::getPosition(window), 600, 5);
				//		std::cout << "new particle effect" << std::endl;
				currentParticleEffect->Emit();
				particleStack.push_back(currentParticleEffect);
			}
		}
	}
}
void Game::update(sf::RenderWindow& window) {
	for (int i = 0; i < particleStack.size(); i++) {
		if (!(particleStack[i]->isAlive())) {
			delete particleStack[i];
			particleStack.erase(particleStack.begin() + i);
		}
		else {
			particleStack[i]->update(window);
		}
	}
}
void Game::render(sf::RenderWindow& window) {
	window.clear();
	for (ParticleEffect* i : particleStack) {
		i->render(window);
	}
	window.display();
}

Game::~Game() {

}

int gm::Rand(int min, int max) // Ranged
{
	static bool setup = true;
	if (setup)
	{
		srand(time(NULL)); //seeding
		setup = false;
	}
	return min + rand() % ((max + 1) - min);
}