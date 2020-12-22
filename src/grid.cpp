#include "precomp.h"

namespace Tmpl8 {
    Grid::Grid(){
        for(int x = 0; x < Grid::NUM_CELLS; x++){
            for(int y = 0; y < Grid::NUM_CELLS; y++){
                cells[x][y] = NULL;
            }
        }
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

        tank->position += tank->speed * tank->max_speed * 0.5f;

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
                if(this->cells[x][y] != NULL){
                    Tank* tank = this->cells[x][y];
                    int tankX = (int)(tank->get_position().x / Grid::CELL_SIZE);
                    int tankY = (int)(tank->get_position().y / Grid::CELL_SIZE);
                    int objectX = (int)(rocket->position.x / Grid::CELL_SIZE);
                    int objectY = (int)(rocket->position.y / Grid::CELL_SIZE);

                    if((tankX == objectX) && (tankY == objectY)){
                        this->handleCell(rocket, tank);
                    }
                }
            }
        }
        rocket->tick(); 
    }

    void Grid::handleAction(Particle_beam* beam){
        for(int x = 0; x < Grid::NUM_CELLS; x++){ 
            for(int y = 0; y < Grid::NUM_CELLS; y++){ 
                if(this->cells[x][y] != NULL){
                    Tank* tank = this->cells[x][y];

                    this->handleCell(beam, tank);

                }
            }
        }
        beam->tick(); 
    }

    void Grid::handleCell(Particle_beam* beam, Tank* tank){
        while(tank != NULL){
            if (tank->active && beam->rectangle.intersects_circle(tank->get_position(), tank->get_collision_radius())) {
                if (tank->hit(50)) {
                    //this->game->smokes.push_back(Smoke(smoke, tank->position - vec2(0, 48)));
                }
            }
            tank = tank->next;
        }
    }

    void Grid::handleCell(Rocket* rocket, Tank* tank){ 

        while(tank != NULL){
            if (tank->active && (tank->allignment != rocket->allignment) && rocket->intersects(tank->position, tank->collision_radius)){            
                //this->game->explosions.push_back(Explosion(&explosion, tank->position));
                if (tank->hit(60)) {
                   // this->game->smokes.push_back(Smoke(smoke, tank->position - vec2(0, 48)));
                }

                rocket->active = false;
                break;
            }  
            tank = tank->next;
        }
    }
}