//Written by Xiangyu Liu
#include "ExplosionEffect.h"
#include "math.h"

using namespace sf;

ExplosionEffect::ExplosionEffect() :ParticleEffect() {}

ExplosionEffect::ExplosionEffect(const sf::Vector2i& position, int lifespan, int particleNum, float intensity, bool loop) :ParticleEffect(sf::Vector2f(position.x,position.y), lifespan, particleNum, loop) {
	this->intensity = intensity;
}

//update
void ExplosionEffect::Update(sf::RenderWindow& window) {
	ParticleEffect::Update(window);

	//changes
	for (int i = 0; i < particles.size(); i++) {
		particles[i]->SetVelocity(Vector2f(particles[i]->GetVelocity().x * 0.98, particles[i]->GetVelocity().y * 0.98));
		dynamic_cast<TriangleParticle*>(particles[i])->SetScale(dynamic_cast<TriangleParticle*>(particles[i])->GetScale() * 0.985);
		particles[i]->SetPosition(Vector2f(particles[i]->GetPosition().x + particles[i]->GetVelocity().x, particles[i]->GetPosition().y + particles[i]->GetVelocity().y));
		if (fabs(particles[i]->GetVelocity().x) + fabs(particles[i]->GetVelocity().y) < 0.5) {
			particles[i]->SetAlive(false);
		}
	}

	//loop here


}
//adds a new particle at the specified index in the particles array (tailor to effects)
void ExplosionEffect::CreateParticle(int index) {
	//TriangleParticle(const sf::Vector2f & position, const sf::Vector2f & velocity, float size, int lifespan, shapeType type);
	TriangleParticle* particle = new TriangleParticle(position, sf::Vector2f(gm::Randf(0 - this->intensity, this->intensity), gm::Randf(0 - this->intensity, this->intensity)), gm::Randf(5, 30), gm::Rand(100, lifespan), TriangleParticle::right, gm::Randf(0.f, 1.5f));
	//rotate to a rand angle
	particle->SetRotate(gm::Randf(0, 360));
	particles[index] = particle;
}

ExplosionEffect::~ExplosionEffect() {
	for (unsigned int i = 0; i < particles.size(); i++) {
		delete particles[i];
	}
}