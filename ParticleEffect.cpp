//Written by Erwang Li
#include "ParticleEffect.h"
#include "CircleParticle.h"

//Constructors
ParticleEffect::ParticleEffect(): lifespan(0), particleNum(0) {}

ParticleEffect::ParticleEffect(const sf::Vector2f &position, int lifespan, int particleNum, bool loop)
: position(position), lifespan(lifespan), particleNum(particleNum), loop(loop), alive(true) {
	particles = std::vector<Particle*>(particleNum, nullptr);
}
//creates a new particle for every element of the particles array
void ParticleEffect::Emit() {
	for (int i = 0; i < particleNum; i++) {
		CreateParticle(i);
	}
}
//adds a new particle at the specified index in the particles array (it should also randomize the particle velocity in some way)
/*void ParticleEffect::CreateParticle(int index) {
	Particle* particle = new Particle(gm::Rand(-20, 20), gm::Rand(-20, 20), float(gm::Rand(2, 10)), gm::Rand(120, 600), sf::Color::White);
	(* particle).SetPosition(Vector2f(float(position.x)- particle->GetSize(), float(position.y)- particle->GetSize()));
	particles[index] = particle;
}*/
void ParticleEffect::Update(sf::RenderWindow& window) {
	for (int i = 0; i < particleNum; i++) {
		particles[i]->Update(window);
	}

	if (!loop) {
		lifespan--;
		if(lifespan <=0)
			alive = false;
	}
}
void ParticleEffect::Render(sf::RenderWindow& window) {
	for (int i = 0; i < particleNum; i++) {
		particles[i]->Render(window);
	}
}

//alive getter
boolean ParticleEffect::isAlive() const{
	return alive;
}

//Destructor
ParticleEffect::~ParticleEffect() {
	for (int i = 0; i < particleNum; i++) {
		delete particles[i];
	}
}