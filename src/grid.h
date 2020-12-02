#pragma once;


namespace Tmpl8 {
    class Grid {
        public:
            Grid();

        private:
            static const int NUM_CELLS = 10;
            static const int CELL_SIZE = 20;

            Tank* cells[NUM_CELLS][NUM_CELLS];
    };
}