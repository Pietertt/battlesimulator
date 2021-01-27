#pragma once

namespace Tmpl8 {

    class Tank;
    class Rocket;
    class Smoke;
    class Particle_beam;

    class Grid;
    class KDTree;
    class ThreadPool;


    class Game
    {
    public:
        Game();
        void set_target(Surface* surface) { screen = surface; }
        void init();
        void shutdown();
        void update(float deltaTime);
        void draw();
        void tick(float deltaTime);
        
        std::vector<Tank*> merge_sort_tanks_health(std::vector<Tank*> unsorted, int depth = 0);
        std::vector<Tank*> merge_tanks_health(std::vector<Tank*> a, std::vector<Tank*> b);
        
        void measure_performance();

        void add_smoke(vec2 position);
        void add_explosion(vec2 position);
        void add_rocket(Tank* tank, vec2 position);

        void mouse_up(int button)
        { /* implement if you want to detect mouse button presses */
        }

        void mouse_down(int button)
        { /* implement if you want to detect mouse button presses */
        }

        void mouse_move(int x, int y)
        { /* implement if you want to detect mouse movement */
        }

        void key_up(int key)
        { /* implement if you want to handle keys */
        }

        void key_down(int key)
        { /* implement if you want to handle keys */
        }

                KDTree* red_tree;
        KDTree* blue_tree;

    private:
        Surface* screen;

        vector<Tank*> tanks;
        vector<Rocket*> rockets;
        vector<Particle_beam*> particle_beams;
        vector<Smoke*> smokes;
        vector<Explosion*> explosions;

        Font* frame_count_font;
        long long frame_count = 0;

        bool lock_update = false;

        int cores = std::thread::hardware_concurrency();

        Grid* grid;
        threading::ThreadPool* pool;

        std::vector<std::thread> threads;
    };
}