#pragma once

namespace objects {
    class Object;
}

namespace Tmpl8 {

    class Grid;
    class Visitor;

    enum allignments {
        BLUE,
        RED
    };

    class Tank : public Object {
        public:
            Tank(Grid* grid, float pos_x, float pos_y, allignments allignment, Sprite* tank_sprite, Sprite* smoke_sprite, float tar_x, float tar_y, float collision_radius, int health, float max_speed);
            ~Tank();

            void tick() override;
            void draw(Surface* screen) override;

            vec2 get_position() override;
            float get_collision_radius() const { return collision_radius; };
            bool rocket_reloaded() const { return reloaded; };

            void reload_rocket();

            void deactivate();
            bool hit(int hit_value);

            int compare_health(const Tank& other) const;

            void push(vec2 direction, float magnitude);

            vec2 position;
            vec2 speed;
            vec2 target;

            int health;

            float collision_radius;
            vec2 force;

            Grid* grid;

            float max_speed;
            float reload_time;

            bool reloaded;
            bool active;

            allignments allignment;

            int current_frame;
            Sprite* tank_sprite;
            Sprite* smoke_sprite;

            Tank* next = NULL;
            Tank* previous = NULL;
            Tank* closest_enemy = NULL;
    };
} 