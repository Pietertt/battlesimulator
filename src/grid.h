#pragma once;

namespace Tmpl8 {
    class Grid {
        public:
            Grid();
            void add(Tank* tank);
            void insertBefore(Tank* tank, Tank* first);
            void handleAction(Rocket* rocket);
            void handleCell(Tank* tank, Rocket* rocket);
            void display();
            void remove(Tank* tank);

            static const int NUM_CELLS = 22;
            static const int CELL_SIZE = 50;
                        Tank* cells[NUM_CELLS][NUM_CELLS];


        private:

    };
}