#pragma once

namespace objects {
    class Object;
}

namespace Tmpl8 {

class Beam : public Object {
    public:
        Beam();
        Beam(vec2 min, vec2 max, Sprite* particle_beam_sprite, int damage);

        void draw(Surface* screen) override;
        void accept(Visitor* visitor, Tank* tank) override;   
        void tick() override; 
        vec2 get_position() override;  

        vec2 min_position;
        vec2 max_position;

        Rectangle2D rectangle;

        int sprite_frame;

        int damage;

        Sprite* particle_beam_sprite;
    };
} 