#include "precomp.h"

namespace Tmpl8 {
    ActionVisitor::ActionVisitor(){

    }

    void ActionVisitor::visit_rocket(Rocket* rocket, Tank* tank){
        if (tank->active && (tank->allignment != rocket->allignment) && rocket->intersects(tank->position, tank->collision_radius)){            

            if (tank->hit(60)) {
               
            }

            rocket->active = false;
        }
    }

    void ActionVisitor::visit_beam(Beam* beam, Tank* tank){
        if (tank->active && beam->rectangle.intersects_circle(tank->get_position(), tank->get_collision_radius())) {
            if (tank->hit(50)) {

            }
        }
    }
}