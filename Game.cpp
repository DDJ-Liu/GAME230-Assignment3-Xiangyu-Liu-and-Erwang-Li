//modified by Erwang Li
#include "Game.h"
#include "ColorfulCirclesEffect.h"
#include "ExplosionEffect.h"
#include "Snow.h"
using namespace gm;

//Global variable
//std::vector<ParticleEffect*> particleStack;
ParticleEffect* currentParticleEffect;

enum particleType{colorfulBubbles,explosion,snow};
particleType type = colorfulBubbles;

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
				
				//currentParticleEffect = new ColorfulCirclesEffect(sf::Mouse::getPosition(window), 600, 30, true);
				//		std::cout << "new particle effect" << std::endl;
				//dynamic_cast<ColorfulCirclesEffect*>(currentParticleEffect)->Emit();
				//particleStack.push_back(currentParticleEffect);
				
				switch (type)
				{
				case particleType::colorfulBubbles:
					currentParticleEffect = new ColorfulCirclesEffect(sf::Mouse::getPosition(window), 600, 30, true);
					dynamic_cast<ColorfulCirclesEffect*>(currentParticleEffect)->Emit();
					break;
				case particleType::explosion:
					currentParticleEffect = new ExplosionEffect(sf::Mouse::getPosition(window), 600, 35, 3.f, false);
					dynamic_cast<ExplosionEffect*>(currentParticleEffect)->Emit();
					break;
				case particleType::snow:
					currentParticleEffect = new Snow(sf::Mouse::getPosition(window), 600, 50, 200.f, true);
					dynamic_cast<Snow*>(currentParticleEffect)->Emit();
					break;
				default:
					std::cout << "type error" << std::endl;
					break;
				}
			}
		}
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Num1) {
				type = particleType::colorfulBubbles;
			}
			if (event.key.code == sf::Keyboard::Num2) {
				type = particleType::explosion;
			}
			if (event.key.code == sf::Keyboard::Num3) {
				type = particleType::snow;
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
	currentParticleEffect->Update(window);
}
void Game::render(sf::RenderWindow& window) {
	window.clear();
	/*for (ParticleEffect* i : particleStack) {
		i->render(window);
	}*/
	if (currentParticleEffect != nullptr)
		currentParticleEffect->Render(window);

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