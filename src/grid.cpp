#include "precomp.h"

namespace Tmpl8 {
    Grid::Grid(Game* game){
        std::cout << &this->action_visitor << std::endl;
        this->game = game;
        // Zet alle cellen op NULL
        for(int x = 0; x < Grid::NUM_CELLS; x++){
            for(int y = 0; y < Grid::NUM_CELLS; y++){
                cells[x][y] = NULL;
                cells[x + 1][y + 1] = NULL;
                cells[x - 1][y - 1] = NULL;
            }
        }
    }

    void Grid::test(ActionVisitor* visitor){
        this->action_visitor = visitor;
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

    void Grid::remove(Tank* tank){
        int cellX = (int)(tank->get_position().x / Grid::CELL_SIZE);
        int cellY = (int)(tank->get_position().y / Grid::CELL_SIZE);

        if(tank->previous == NULL){
            this->cells[cellX][cellY] = tank->next;
        } else {
            tank->previous->next = tank->next;
        }

        if(tank->next == NULL){
            this->cells[cellX][cellY] = tank->previous;
        } else {
            tank->next->previous = tank->previous;
        }
    }



    void Grid::display(){
        for(int x = 0; x < Grid::NUM_CELLS; x++){
            for(int y = 0; y < Grid::NUM_CELLS; y++){  
                if(Grid::cells[x][y] != NULL){
                    std::cout << Grid::cells[x][y] << " ";
                }
            }
        }
        std::cout << std::endl;
    }

    void Grid::handleAction(Object* object){
        for(int x = 0; x < Grid::NUM_CELLS; x++){ // N
            for(int y = 0; y < Grid::NUM_CELLS; y++){ // N
                this->handleCell(this->cells[x][y], object); // 1
            }
        }
        object->tick(); // 1
    }

    void Grid::handleCell(Tank* tank, Object* object){ 

        // // Skip alle cellen die op NULL staan
        while(tank != NULL){
            int tankX = (int)(tank->get_position().x / Grid::CELL_SIZE);
            int tankY = (int)(tank->get_position().y / Grid::CELL_SIZE);
            int objectX = (int)(object->get_position().x / Grid::CELL_SIZE);
            int objectY = (int)(object->get_position().y / Grid::CELL_SIZE);

            if(tankX > objectX - object->range){
                if(tankX < objectX + object->range){
                    if(tankY > objectY - object->range){
                        if(tankY < objectY + object->range){
                             object->accept(this->action_visitor, tank);   
                        }
                    }
                }
            }

            
            // if (tank->active && (tank->allignment != rocket->allignment) && rocket->intersects(tank->position, tank->collision_radius)){            

            //     if (tank->hit(60))
            //     {
            //         //smokes.push_back(Smoke(smoke, tank.position - vec2(0, 48)));
            //     }

            //     rocket->active = false;
            //     break;
            // }
            

            // Doorloop de lijst
            tank = tank->next; // SEGFAULT
           
        }

        //std::cout << "End of cell" << std::endl;
    }
}