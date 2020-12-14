#include "precomp.h"

namespace Tmpl8 {
    Grid::Grid(){
        // Zet alle cellen op NULL
        for(int x = 0; x < Grid::NUM_CELLS; x++){
            for(int y = 0; y < Grid::NUM_CELLS; y++){
                cells[x][y] = NULL;
            }
        }
    }

    void Grid::add(Tank* tank){

        std::cout << "Added -> " << &tank << std::endl;

        // De cell waarin de tank zich op het moment zich bevind
        int cellX = (int)(tank->get_position().x / Grid::CELL_SIZE);
        int cellY = (int)(tank->get_position().y / Grid::CELL_SIZE);

        // Zet de HEAD op NULL
        tank->previous = NULL;

        // Zet de tail op de huidige cell
        tank->next = cells[cellX][cellY];

        cells[cellX][cellY] = tank;

        // Voeg de tank aan de HEAD van de huidige cell toe wanneer er al een tank in de cell zit
        if(tank->next != NULL){
            tank->next->previous = tank;
        }

        //std::cout << "TANK ->" << &tank << " NEXT -> " << &tank->next << " PREV -> " << &tank->previous << std::endl;

        // Zet de tank in de huidige cell

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

    void Grid::handleAction(){
        for(int x = 0; x < Grid::NUM_CELLS; x++){
            for(int y = 0; y < Grid::NUM_CELLS; y++){
                this->handleCell(this->cells[x][y]);
                //Grid::display();
            }
        }

        std::cout << "Next rocket" << std::endl;
    }

    void Grid::handleCell(Tank* tank){ 

        // // Skip alle cellen die op NULL staan
        while(tank != NULL){
            std::cout << &tank << std::endl;

            if(tank == tank->next){
                std::cout << "Tank " << tank << " nfext " << tank->next << std::endl;
                break;
            }

            // Doorloop de lijst
            tank = tank->next; // SEGFAULT
           
        }

        std::cout << "End of cell" << std::endl;
    }
}