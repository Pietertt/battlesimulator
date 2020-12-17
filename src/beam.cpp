#include "precomp.h"

namespace Tmpl8 {

Beam::Beam() : min_position(), max_position(), particle_beam_sprite(nullptr), sprite_frame(0), rectangle(), damage(1) {
    this->range = 0;
}

Beam::Beam(vec2 min, vec2 max, Sprite* particle_beam_sprite, int damage) : particle_beam_sprite(particle_beam_sprite), sprite_frame(0), damage(damage) {
    min_position = min;
    max_position = min + max;

    rectangle = Rectangle2D(min_position, max_position);
}

void Beam::tick() {

    if (++sprite_frame == 30)
    {
        sprite_frame = 0;
    }
}

void Beam::draw(Surface* screen) {
    vec2 position = rectangle.min;

    const int offsetX = 23;
    const int offsetY = 137;

    particle_beam_sprite->set_frame(sprite_frame / 10);
    particle_beam_sprite->draw(screen, (int)(position.x - offsetX), (int)(position.y - offsetY));
}

vec2 Beam::get_position(){
    return this->max_position;
}

void Beam::accept(Visitor* visitor, Tank* tank) {
    visitor->visit_beam(this, tank);
}

} // namespace Tmpl8