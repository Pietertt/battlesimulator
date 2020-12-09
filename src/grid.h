#pragma once;

namespace Tmpl8 {
    class Grid {
        public:
            Grid();
            void add(Tank* tank);
            void handleAction(Rocket* rocket);
            void handleCell(Tank* tank, Rocket* rocket);
            void display();

        private:
            static const int NUM_CELLS = 100;
            static const int CELL_SIZE = 20;

            Tank* cells[NUM_CELLS][NUM_CELLS];
    };
}