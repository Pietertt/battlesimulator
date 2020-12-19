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

    Grid::Grid(Game* game){
        this->game = game;
        // Zet alle cellen op NULL
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

        std::cout << cellX << " " << cellY << " " << oldCellX << " " << oldCellY << std::endl;

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
                    int objectX = (int)(rocket->get_position().x / Grid::CELL_SIZE);
                    int objectY = (int)(rocket->get_position().y / Grid::CELL_SIZE);

                    if((tankX == objectX) && (tankY == objectY)){
                        this->handleCell(tank, rocket);
                    }
                }
            }
        }
        rocket->tick(); 
    }

    void Grid::handleAction(Beam* beam){
        for(int x = 0; x < Grid::NUM_CELLS; x++){ // N
            for(int y = 0; y < Grid::NUM_CELLS; y++){ // N
                if(this->cells[x][y] != NULL){
                    Tank* tank = this->cells[x][y];
                    int tankX = (int)(tank->get_position().x / Grid::CELL_SIZE);
                    int tankY = (int)(tank->get_position().y / Grid::CELL_SIZE);
                    int objectX = (int)(beam->get_position().x / Grid::CELL_SIZE);
                    int objectY = (int)(beam->get_position().y / Grid::CELL_SIZE);

                    if((tankX == objectX) && (tankY == objectY)){
                        this->handleCell(tank, beam);
                    }
                }
            }
        }
        beam->tick(); 
    }

    void Grid::handleCell(Tank* tank, Beam* beam){
        while(tank != NULL){
            if (tank->active && beam->rectangle.intersects_circle(tank->get_position(), tank->get_collision_radius())) {
                if (tank->hit(50)) {
                    this->game->smokes.push_back(Smoke(smoke, tank->position - vec2(0, 48)));
                }
            }
            tank = tank->next;
        }
    }

    void Grid::handleCell(Tank* tank, Rocket* object){ 

        while(tank != NULL){
            if (tank->active && (tank->allignment != object->allignment) && object->intersects(tank->position, tank->collision_radius)){            
                this->game->explosions.push_back(Explosion(&explosion, tank->position));
                if (tank->hit(60)) {
                    this->game->smokes.push_back(Smoke(smoke, tank->position - vec2(0, 48)));
                }

                object->active = false;
            }  
            tank = tank->next;
        }
    }
}