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
        tank->next = this->cells[cellX][cellY];

        if(tank->next != NULL){
            tank->next = tank;
        }
    }

    void Grid::handleAction(){
        for(int x = 0; x < Grid::NUM_CELLS; x++){
            for(int y = 0; y < Grid::NUM_CELLS; y++){
                this->handleCell(this->cells[x][y]);
            }
        }
    }

    void Grid::handleCell(Tank* tank){
        while(tank != NULL){
            Tank* other = tank->next;
            while(other != NULL){
                if(tank->get_position().x == other->get_position().x && tank->get_position().y == other->get_position().y){
                    std::cout << "Hit!" << std::endl;
                }
                other = other->next;
            }
            tank = tank->next;
        }
    }
}