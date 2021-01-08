#include "precomp.h"
#include "tank.h"


namespace Tmpl8 {
    Tank::Tank(
        float pos_x,
        float pos_y,
        allignments allignment,
        Sprite* tank_sprite,
        Sprite* smoke_sprite,
        Grid* grid,
        float tar_x,
        float tar_y,
        float collision_radius,
        int health,
        float max_speed)
        : position(pos_x, pos_y),
        allignment(allignment),
        target(tar_x, tar_y),
        health(health),
        collision_radius(collision_radius),
        max_speed(max_speed),
        force(0, 0),
        reload_time(1),
        reloaded(false),
        speed(0),
        active(true),
        current_frame(0),
        tank_sprite(tank_sprite),
        smoke_sprite(smoke_sprite),
        grid(grid)
    {
    }

    Tank::~Tank() {
    }

    void Tank::tick() {
        if (--reload_time <= 0.0f) reloaded = true;
        if (++current_frame > 8) current_frame = 0;
    }

    void Tank::reload_rocket() {
        reloaded = false, reload_time = 200.0f;
    }

    void Tank::deactivate() {
        active = false;
    }

    bool Tank::hit(int hit_value) {
        health -= hit_value;

        if (health <= 0)
        {
            this->deactivate();
            return true;
        }

        return false;
    }

    void Tank::draw(Surface* screen) {
        vec2 direction = (target - position).normalized();
        tank_sprite->set_frame(((abs(direction.x) > abs(direction.y)) ? ((direction.x < 0) ? 3 : 0) : ((direction.y < 0) ? 9 : 6)) + (current_frame / 3));
        tank_sprite->draw(screen, (int)position.x - 14, (int)position.y - 18);
    }

    int Tank::compare_health(Tank* other) {
        return ((health == other->health) ? 0 : ((health > other->health) ? 1 : -1));
    }

    int Tank::compare_position(Tank* other, int depth) {   
        if(depth % 2 == 0){
            if(this->get_position().x >= other->get_position().x){
                return 1;
            } else {
                return -1;
            }
        } else {
            if(this->get_position().y >= other->get_position().y){
                return 1;
            } else {
                return -1;
            }
        }
    }

    float Tank::get_distance(Tank* other) {
        float x1 = this->get_position().x;
        float y1 = this->get_position().y;
        float x2 = other->get_position().x;
        float y2 = other->get_position().y;

        float dx = x1 - x2;
        float dy = y1 - y2;

        return sqrt(dx * dx + dy * dy);
    }

   void Tank::push(vec2 direction, float magnitude)
{
    force += direction * magnitude;
}

} 