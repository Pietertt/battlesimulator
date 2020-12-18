#pragma once;

namespace objects {
    class Object;
}

namespace Tmpl8 {

    class Game;
    class ActionVisitor;

    class Grid {
        public:
            Grid(Game* game);
            void add(Tank* tank);
            void handleAction(Rocket* rocket);
            void handleAction(Tank* tank);
            void handleAction(Beam* beam);
            void handleCell(Tank* tank, Tank* other);
            void handleCell(Tank* tank, Rocket* rocket);
            void handleCell(Tank* tank, Beam* beam);

            Game* game = NULL;

            static const int NUM_CELLS = 30;
            static const int CELL_SIZE = 50;

            Tank* cells[NUM_CELLS][NUM_CELLS];



        private:
    };
}