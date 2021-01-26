#pragma once

namespace Tmpl8 {

    class Tank;
    class Rocket;
    class Game;

    class Grid {
        public:
            Grid(Game* game);
            void add(Tank* tank);
            void move(Tank* tank);

            void handleAction(Rocket* rocket);
            void handleCell(Rocket* rocket, int x, int y);
            bool handleUnit(Rocket* rocket, Tank* tank);

            void handleAction(Particle_beam* beam);
            void handleCell(Particle_beam* beam, int x, int y);
            void handleUnit(Particle_beam* beam, Tank* tank);

            void handleAction(Tank* tank);
            void handleCell(Tank* tank, int x, int y);
            void handleUnit(Tank* tank, Tank* other);

            static const int NUM_CELLS = 30;
            static const int CELL_SIZE = 50;

            Tank* cells[NUM_CELLS][NUM_CELLS];

        private:
            Game* game;
    };
} 