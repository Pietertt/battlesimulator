#include "precomp.h"

namespace Tmpl8 {
    Grid::Grid(Game* game){
        for(int x = 0; x < Grid::NUM_CELLS; x++){
            for(int y = 0; y < Grid::NUM_CELLS; y++){
                cells[x][y] = NULL;
            }
        }

        this->game = game;
    }

    void Grid::add(Tank* tank){

        // De cell waarin de tank zich op het moment zich bevind
        int cellX = (int)(tank->get_position().x / Grid::CELL_SIZE);
        int cellY = (int)(tank->get_position().y / Grid::CELL_SIZE);

        // Zet de HEAD op NULL
        tank->previous = NULL;

        // Zet de tail op de huidige cell
        tank->next = cells[cellX][cellY];

        // Zet de tank in de desbetreffende cell
        cells[cellX][cellY] = tank;

        // Voeg de tank aan de HEAD van de huidige cell toe wanneer er al een tank in de cell zit
        if(tank->next != NULL){
            tank->next->previous = tank;
        }
    }

    void Grid::move(Tank* tank){
        int oldCellX = (int)(tank->get_position().x / Grid::CELL_SIZE);
        int oldCellY = (int)(tank->get_position().y / Grid::CELL_SIZE);

        if(isnan(tank->force.x)) tank->force = vec2(0.f, 0.f);
        if(isnan(tank->force.y)) tank->force = vec2(0.f, 0.f);

        vec2 direction = (tank->target - tank->position).normalized();
        tank->speed = direction + tank->force;
        tank->position += tank->speed * tank->max_speed * 0.5f;
        tank->force = vec2(0.f, 0.f);

        int cellX = (int)(tank->get_position().x / Grid::CELL_SIZE);
        int cellY = (int)(tank->get_position().y / Grid::CELL_SIZE);

        if(oldCellX == cellX && oldCellY == cellY) return;

        if(tank->previous != NULL){
            tank->previous->next = tank->next;
        }

        if(tank->next != NULL){
            tank->next->previous = tank->previous;
        }

        if(this->cells[oldCellX][oldCellY] == tank){
            this->cells[oldCellX][oldCellY] = tank->next;
        }
        this->add(tank);
    }

    void Grid::handleAction(Rocket* rocket){
        for(int x = 0; x < Grid::NUM_CELLS; x++){ 
            for(int y = 0; y < Grid::NUM_CELLS; y++){ 
                int cellX = (int)(rocket->position.x / Grid::CELL_SIZE);
                int cellY = (int)(rocket->position.y / Grid::CELL_SIZE);
                if(cellX == x && cellY == y){
                    if(this->cells[x][y] != NULL){
                        this->handleCell(rocket, x, y); 
                    }
                }
            }
        }
        rocket->tick(); 
    }

    void Grid::handleCell(Rocket* rocket, int x, int y){ 
        Tank* tank = this->cells[x][y];
        while(tank != NULL){
            if (this->handleUnit(rocket, tank)) break;
            if ((x > 0 && y > 0) && (this->cells[x - 1][y - 1] != NULL)) if (this->handleUnit(rocket, this->cells[x - 1][y - 1])) break;
            if ((x > 0) && (this->cells[x - 1][y] != NULL)) if (this->handleUnit(rocket, this->cells[x - 1][y])) break;
            if ((y > 0) && (this->cells[x][y - 1] != NULL)) if (this->handleUnit(rocket, this->cells[x][y - 1])) break;
            if ((x > 0 && y < this->NUM_CELLS - 1) && (this->cells[x - 1][y + 1] != NULL)) if (this->handleUnit(rocket, this->cells[x - 1][y + 1])) break;
            tank = tank->next;
        }
    }

    bool Grid::handleUnit(Rocket* rocket, Tank* tank){
        if (tank->active && rocket->active && (tank->allignment != rocket->allignment) && rocket->intersects(tank->position, tank->collision_radius)){            
            this->game->add_explosion(tank->position);
            if (tank->hit(60)) {
                this->game->add_smoke(tank->position);
            }
            rocket->active = false;
            return true;
        }  
        return false;
    }

    void Grid::handleAction(Particle_beam* beam){
        for(int x = 0; x < Grid::NUM_CELLS; x++){ 
            for(int y = 0; y < Grid::NUM_CELLS; y++){ 
                if(this->cells[x][y] != NULL){
                    this->handleCell(beam, x, y);
                }
            }
        }
        beam->tick(); 
    }

    void Grid::handleCell(Particle_beam* beam, int x, int y){
        Tank* tank = this->cells[x][y];
        while(tank != NULL){
            this->handleUnit(beam, tank);
            if((x > 0 && y > 0) && (this->cells[x - 1][y - 1] != NULL)) this->handleUnit(beam, this->cells[x - 1][y - 1]);
            if((x > 0) && (this->cells[x - 1][y] != NULL)) this->handleUnit(beam, this->cells[x - 1][y]);
            if((y > 0) && (this->cells[x][y - 1] != NULL)) this->handleUnit(beam, this->cells[x][y - 1]);
            if((x > 0 && y < this->NUM_CELLS - 1) && (this->cells[x - 1][y + 1] != NULL)) this->handleUnit(beam, this->cells[x - 1][y + 1]);

            tank = tank->next;
        }
    }

    void Grid::handleUnit(Particle_beam* beam, Tank* tank){
        if (tank->active && beam->rectangle.intersects_circle(tank->get_position(), tank->get_collision_radius())) {
            if (tank->hit(50)) {
                this->game->add_smoke(tank->position);
            }
        }
    }

    void Grid::handleAction(Tank* tank){
        int counter = 0;
        for(int x = 0; x < Grid::NUM_CELLS; x++){ 
            for(int y = 0; y < Grid::NUM_CELLS; y++){ 
                if(this->cells[x][y] != NULL){
                    if (tank->get_distance(this->cells[x][y]) < tank->get_collision_radius()) {
                        this->handleCell(tank, x, y);
                    }
                }
            }
        }
        tank->tick();
        this->move(tank);

        if (tank->rocket_reloaded()) {
            Tank* current_best = NULL;
            float best_distance = 10000;

            if(tank->allignment == BLUE){
                this->game->red_tree->nearest_neighbour_search(this->game->red_tree, tank, current_best, best_distance, 0);
            } else {
                this->game->blue_tree->nearest_neighbour_search(this->game->blue_tree, tank, current_best, best_distance, 0);
            }
        
            if(current_best != NULL){
                this->game->add_rocket(tank, (current_best->get_position() - tank->position).normalized() * 3);
                tank->reload_rocket();
            }
        }
    }

    void Grid::handleCell(Tank* tank, int x, int y){ 
        Tank* other = this->cells[x][y];
        while(other != NULL){
            if(tank != other) {
                this->handleUnit(tank, other);   
                if((x > 0 && y > 0) && (this->cells[x - 1][y - 1] != NULL)) this->handleUnit(tank, this->cells[x - 1][y - 1]);
                if((x > 0) && (this->cells[x - 1][y] != NULL)) this->handleUnit(tank, this->cells[x - 1][y]);
                if((y > 0) && (this->cells[x][y - 1] != NULL)) this->handleUnit(tank, this->cells[x][y - 1]);
                if((x > 0 && y < this->NUM_CELLS - 1) && (this->cells[x - 1][y + 1] != NULL)) this->handleUnit(tank, this->cells[x - 1][y + 1]);
            }
            other = other->next;
        }
    }

    void Grid::handleUnit(Tank* tank, Tank* other) {         
        
        vec2 dir = tank->get_position() - other->get_position();
        
        float dirSquaredLen = dir.sqr_length();

        float colSquaredLen = (tank->get_collision_radius() + other->get_collision_radius());
        colSquaredLen *= colSquaredLen;

        if (dirSquaredLen < colSquaredLen) {
            tank->push(dir.normalized(), 1.f);
        }
    }   
}