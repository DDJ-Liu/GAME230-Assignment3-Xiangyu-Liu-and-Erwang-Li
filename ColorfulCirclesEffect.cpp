#include "ColorfulCirclesEffect.h"
#include "CircleParticle.h"

using namespace sf;

ColorfulCirclesEffect::ColorfulCirclesEffect() : ParticleEffect() {}

ColorfulCirclesEffect::ColorfulCirclesEffect(const Vector2i& position, int lifespan, int particleNum, bool loop)
    : ParticleEffect(Vector2f(float(position.x), float(position.y)), lifespan, particleNum, loop) {
}

//Update
void ColorfulCirclesEffect::Update(RenderWindow& window) {
    ParticleEffect::Update(window);
    int hue;
    float sat, val;
    for (unsigned int i = 0; i < particles.size(); i++) {
        if (particles[i]->isAlive()) {
            hue = dynamic_cast<CircleParticle*>(particles[i])->GetHSVColor().hue;
            sat = dynamic_cast<CircleParticle*>(particles[i])->GetHSVColor().sat;
            val = dynamic_cast<CircleParticle*>(particles[i])->GetHSVColor().val;
            if (sat <= 0.45f) {
                sat += 0.005f;
            }
            else if (sat > 0.45f) {
                sat = 0.45f;
            }
            if (hue <= 360) {
                hue += 1;
            }
            else {
                hue = 0;
            }
            dynamic_cast<CircleParticle*>(particles[i])->SetHSVColor(hue, sat, val);
            Color brushColor = gm::hsv(hue, sat, val);
            dynamic_cast<CircleParticle*>(particles[i])->SetColor(brushColor.r, brushColor.g, brushColor.b, brushColor.a);
            dynamic_cast<CircleParticle*>(particles[i])->SetPosition(
                Vector2f(dynamic_cast<CircleParticle*>(particles[i])->GetPosition().x + dynamic_cast<CircleParticle*>(particles[i])->GetVelocity().x,
                    dynamic_cast<CircleParticle*>(particles[i])->GetPosition().y + dynamic_cast<CircleParticle*>(particles[i])->GetVelocity().y));
            //particle.setPosition(particle.getPosition() + Vector2f(velocity.x / 10, velocity.y / 10));
        }
        //Looping functionality
        if (loop && (!particles[i]->isAlive())) {
            particles[i]->Reset(position, Vector2f(gm::Randf(-1.f, 1.f), gm::Randf(-1.f, 1.f)), gm::Rand(100, 600));
        }
    }
}
//Adds a new particle at the specified index in the particles array (tailor to effects)
void ColorfulCirclesEffect::CreateParticle(int index) {
        CircleParticle* particle = new CircleParticle(position, Vector2f(gm::Randf(-1.f, 1.f), gm::Randf(-1.f, 1.f)), float(gm::Rand(2, 15)), gm::Rand(100, lifespan));
        int hue = gm::Rand(0,360);
        float sat = gm::Randf(0.2f, 0.4f);
        float val = gm::Randf(0.8f, 1.f);
        particle->SetHSVColor(hue, sat, val);
        Color brushColor = gm::hsv(hue, sat, val);
        particle->SetColor(brushColor.r, brushColor.g, brushColor.b, brushColor.a);
        particle->SetPosition(Vector2f(float(position.x) - particle->GetRadius(), float(position.y) - particle->GetRadius()));
        particles[index] = particle;
}

//Destructor
ColorfulCirclesEffect::~ColorfulCirclesEffect() {
    for (unsigned int i = 0; i < particles.size(); i++) {
        delete particles[i];
    }
}



/*    if (HSVcolor.sat <= 0.45f) {
        HSVcolor.sat += 0.005f;
    }
    else if (HSVcolor.sat > 0.45f) {
        HSVcolor.sat = 0.45f;
    }
    if (HSVcolor.hue <= 360.f) {
        HSVcolor.hue += 1.f;
    }
    else {
        HSVcolor.hue = 0.f;
    }*/