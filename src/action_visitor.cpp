#include "precomp.h"

namespace Tmpl8 {
    static Surface* background_img = new Surface("/Users/pieterboersma/Desktop/battlesimulator/assets/Background_Grass.png");
static Surface* tank_red_img = new Surface("/Users/pieterboersma/Desktop/battlesimulator/assets/Tank_Proj2.png");
static Surface* tank_blue_img = new Surface("/Users/pieterboersma/Desktop/battlesimulator/assets/Tank_Blue_Proj2.png");
static Surface* rocket_red_img = new Surface("/Users/pieterboersma/Desktop/battlesimulator/assets/Rocket_Proj2.png");
static Surface* rocket_blue_img = new Surface("/Users/pieterboersma/Desktop/battlesimulator/assets/Rocket_Blue_Proj2.png");
static Surface* particle_beam_img = new Surface("/Users/pieterboersma/Desktop/battlesimulator/assets/Particle_Beam.png");
static Surface* smoke_img = new Surface("/Users/pieterboersma/Desktop/battlesimulator/assets/Smoke.png");
static Surface* explosion_img = new Surface("/Users/pieterboersma/Desktop/battlesimulator/assets/Explosion.png");

static Sprite background(background_img, 1);
static Sprite tank_red(tank_red_img, 12);
static Sprite tank_blue(tank_blue_img, 12);
static Sprite rocket_red(rocket_red_img, 12);
static Sprite rocket_blue(rocket_blue_img, 12);
static Sprite smoke(smoke_img, 4);
static Sprite explosion(explosion_img, 9);
static Sprite particle_beam_sprite(particle_beam_img, 3);


    ActionVisitor::ActionVisitor(){

    }

    void ActionVisitor::visit_rocket(Rocket* rocket, Tank* tank){
        if (tank->active && (tank->allignment != rocket->allignment) && rocket->intersects(tank->position, tank->collision_radius)){            

            if (tank->hit(60)) {
               
            }

            rocket->active = false;
        }
    }

    void ActionVisitor::add(Game* game){
        this->game = game;
    }

    void ActionVisitor::visit_beam(Beam* beam, Tank* tank){
        if (tank->active && beam->rectangle.intersects_circle(tank->get_position(), tank->get_collision_radius())) {
            if (tank->hit(50)) {

            }
        }
    }

    void ActionVisitor::visit_tank(Tank* tank, Tank* other){
        vec2 dir = tank->get_position() - other->get_position();
        float dirSquaredLen = dir.sqr_length();

        float colSquaredLen = (tank->get_collision_radius() + other->get_collision_radius());
        colSquaredLen *= colSquaredLen;

        if (dirSquaredLen < colSquaredLen) {
            tank->push(dir.normalized(), 1.f);
        }

        if (tank->rocket_reloaded()) {
            float closest_distance = numeric_limits<float>::infinity();
            int closest_index = 0;

       
            if (other->allignment != tank->allignment && other->active) {
                float sqrDist = fabsf((other->get_position() - tank->get_position()).sqr_length());
                if (sqrDist < closest_distance) {
                    closest_distance = sqrDist;
                    tank->closest_enemy = other;
                }
            }
                // Tank& target = find_closest_enemy(tank);

            if(tank->closest_enemy != NULL){
                Rocket* rocket = new Rocket(tank->position, (other->get_position() - tank->position).normalized() * 3, 10.0f, tank->allignment, ((tank->allignment == RED) ? &rocket_red : &rocket_blue));
                game->rockets.push_back(rocket);
                tank->reload_rocket();
            }
                // rockets.push_back(Rocket(tank.position, (target.get_position() - tank.position).normalized() * 3, rocket_radius, tank.allignment, ((tank.allignment == RED) ? &rocket_red : &rocket_blue)));

                // tank.reload_rocket();
        }
    }
}