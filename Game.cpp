//modified by Erwang Li
#include "Game.h"
#include "ColorfulCirclesEffect.h"
using namespace gm;

//Global variable
//std::vector<ParticleEffect*> particleStack;
ParticleEffect* currentParticleEffect;

Game::Game() {

}

void Game::handleInput(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
		//LMB temporary particle 1
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Button::Left) {
				if (currentParticleEffect != nullptr)
					delete currentParticleEffect;
				currentParticleEffect = new ColorfulCirclesEffect(sf::Mouse::getPosition(window), 600, 30, true);
				//		std::cout << "new particle effect" << std::endl;
				dynamic_cast<ColorfulCirclesEffect*>(currentParticleEffect)->Emit();
				//particleStack.push_back(currentParticleEffect);
			}
		}
	}
}
void Game::update(sf::RenderWindow& window) {
	/*for (int i = 0; i < particleStack.size(); i++) {
		if (!(particleStack[i]->isAlive())) {
			delete particleStack[i];
			particleStack.erase(particleStack.begin() + i);
		}
		else {
			particleStack[i]->update(window);
		}
	}*/
	if(currentParticleEffect != nullptr)
		dynamic_cast<ColorfulCirclesEffect*>(currentParticleEffect)->Update(window);
}
void Game::render(sf::RenderWindow& window) {
	window.clear();
	/*for (ParticleEffect* i : particleStack) {
		i->render(window);
	}*/
	if (currentParticleEffect != nullptr)
		dynamic_cast<ColorfulCirclesEffect*>(currentParticleEffect)->Render(window);
	window.display();
}

Game::~Game() {

}

//Help functions
int gm::Rand(int min, int max) // Ranged
{
	static bool setup = true;
	if (setup)
	{
		srand(time(NULL)); //seeding
		setup = false;
	}
	int tmp = min + rand() % ((max + 1) - min);
	return (tmp == 0) ? 1 : tmp;
}

float gm::Randf(float min, float max) {
	static bool setup = true;
	if (setup)
	{
		srand(time(NULL)); //seeding
		setup = false;
	}
	return (min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min))) );
}

//Implementation of HSV Tool Function by Tenry
sf::Color gm::hsv(int hue, float sat, float val)
{
	hue %= 360;
	while (hue < 0) hue += 360;

	if (sat < 0.f) sat = 0.f;
	if (sat > 1.f) sat = 1.f;

	if (val < 0.f) val = 0.f;
	if (val > 1.f) val = 1.f;

	int h = hue / 60;
	float f = float(hue) / 60 - h;
	float p = val * (1.f - sat);
	float q = val * (1.f - sat * f);
	float t = val * (1.f - sat * (1 - f));

	switch (h)
	{
	default:
	case 0:
	case 6: return sf::Color(val * 255, t * 255, p * 255);
	case 1: return sf::Color(q * 255, val * 255, p * 255);
	case 2: return sf::Color(p * 255, val * 255, t * 255);
	case 3: return sf::Color(p * 255, q * 255, val * 255);
	case 4: return sf::Color(t * 255, p * 255, val * 255);
	case 5: return sf::Color(val * 255, p * 255, q * 255);
	}
}