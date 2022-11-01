//Written by Xiangyu Liu
#include "Snow.h"

using namespace sf;

Snow::Snow() :ParticleEffect() {}

Snow::Snow(const sf::Vector2i& position, int lifespan, int particleNum, float width, bool loop) :ParticleEffect(sf::Vector2f(position.x, position.y), lifespan, particleNum, loop) {
	this->width = width;
}

//update
void Snow::Update(sf::RenderWindow& window) {
	ParticleEffect::Update(window);

	//changes
	for (int i = 0; i < particles.size(); i++) {
		particles[i]->SetVelocity(Vector2f(particles[i]->GetVelocity().x + gm::Randf(-0.05f, 0.05f), particles[i]->GetVelocity().y));
		particles[i]->SetPosition(Vector2f(particles[i]->GetPosition().x + particles[i]->GetVelocity().x, particles[i]->GetPosition().y + particles[i]->GetVelocity().y));
		if (fabs(particles[i]->GetVelocity().x) + fabs(particles[i]->GetVelocity().y) < 0.5) {
			particles[i]->SetAlive(false);
		}


		//loop here
		if (loop && (!particles[i]->isAlive())) {
			particles[i]->Reset(Vector2f(position.x + gm::Randf(-width / 2, width / 2), position.y), Vector2f(0, gm::Randf(1.f, 1.2f)), gm::Rand(150, 400));
		}
	}
}
//adds a new particle at the specified index in the particles array (tailor to effects)
void Snow::CreateParticle(int index) {
	CircleParticle* particle = new CircleParticle(Vector2f(position.x + gm::Randf(-width / 2, width / 2), position.y), Vector2f(0, gm::Randf(1.f, 1.2f)), gm::Randf(3.f, 7.f), gm::Rand(150,400));
	particles[index] = particle;
}

Snow::~Snow() {
	for (unsigned int i = 0; i < particles.size(); i++) {
		delete particles[i];
	}
}
