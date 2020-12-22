#pragma once

namespace Tmpl8 {

    class Tank;
    class Rocket;

    class Grid {
        public:
            Grid();
            void add(Tank* tank);
            void move(Tank* tank);

            void handleAction(Rocket* rocket);
            void handleAction(Particle_beam* beam);
            void handleCell(Particle_beam* beam, Tank* tank);
            void handleCell(Rocket* rocket, Tank* tank);

            static const int NUM_CELLS = 30;
            static const int CELL_SIZE = 50;

            Tank* cells[NUM_CELLS][NUM_CELLS];
    };
} 