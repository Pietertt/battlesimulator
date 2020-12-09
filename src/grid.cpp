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
        int cellX = (int)(tank->get_position().x / Grid::CELL_SIZE);
        int cellY = (int)(tank->get_position().y / Grid::CELL_SIZE);

        tank->previous = NULL;
        tank->next = cells[cellX][cellY];
    
        if(cells[cellX][cellY] != NULL){
            cells[cellX][cellY]->previous = tank;
            cells[cellX][cellY] = tank;

        }
    }

    void Grid::display(){
        for(int x = 0; x < Grid::NUM_CELLS; x++){
            for(int y = 0; y < Grid::NUM_CELLS; y++){  
                std::cout << y << std::endl;
            }
            std::cout << x << std::endl;
        }
    }

    void Grid::handleAction(Rocket* rocket){
        for(int x = 0; x < Grid::NUM_CELLS; x++){
            for(int y = 0; y < Grid::NUM_CELLS; y++){
                this->handleCell(this->cells[x][y], rocket);
            }
        }
        rocket->tick();
    }

    void Grid::handleCell(Tank* tank, Rocket* rocket){ 
        while(true){
            if(tank == NULL){
                break;
            }
            std::cout << tank << std::endl;
            tank = tank->next;
            
        }        
    }
}