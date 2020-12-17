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
            void insertBefore(Tank* tank, Tank* first);
            void handleAction(Object* rocket);
            void handleCell(Tank* tank, Object* rocket);
            void display();
            void remove(Tank* tank);

            void test(ActionVisitor* visitor);

            Game* game = NULL;

            ActionVisitor* action_visitor = NULL;

            static const int NUM_CELLS = 22;
            static const int CELL_SIZE = 100;
            Tank* cells[NUM_CELLS][NUM_CELLS];



        private:

    };
}