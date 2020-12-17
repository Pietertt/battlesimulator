#pragma once

namespace objects {
    class Object;
}

namespace Tmpl8 {

    class Rocket : public Object {
    public:
        Rocket(vec2 position, vec2 direction, float collision_radius, allignments allignment, Sprite* rocket_sprite);
        Rocket();
        ~Rocket();
        
        bool intersects(vec2 position_other, float radius_other) const;

        void draw(Surface* screen) override;
        void accept(Visitor* visitor, Tank* tank) override;   
        void tick() override;  
        vec2 get_position() override;

        vec2 position;
        vec2 speed;

        float collision_radius;

        bool active;

        allignments allignment;

        int current_frame;
        Sprite* rocket_sprite;
    };

} // namespace Tmpl8