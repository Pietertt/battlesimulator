#include "precomp.h"

namespace Tmpl8 {
    Grid::Grid(){
        for(int x = 0; x < NUM_CELLS; x++){
            for(int y = 0; y < NUM_CELLS; y++){
                cells[x][y] = NULL;
            }
        }
    }
}