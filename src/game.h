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
        
        static std::vector<Tank*> merge_sort_tanks_health(std::vector<Tank*> unsorted);
        static std::vector<Tank*> merge_tanks_health(std::vector<Tank*> a, std::vector<Tank*> b);
        
        void measure_performance();

        void add_smoke(vec2 position);
        void add_explosion(vec2 position);

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

        KDTree* red_tree;
        KDTree* blue_tree;

        int cores = std::thread::hardware_concurrency();
        int max_threads = this->cores * 8;

        Grid* grid;
        threading::ThreadPool* pool;

        std::vector<std::thread> threads;

        template <typename T> void execute_parallel(std::vector<T*> elements) {
            if (this->cores == 0) {
                for (T* element : elements) {
                    this->grid->handleAction(element);
                }
            } else {
                for (int i = 0; i < this->max_threads; i++) {
                    int part = elements.size() / this->max_threads;

                    if ((elements.size() % 2 == 0) || ((elements.size() % 2 != 0) && (i != max_threads - 1))) {
                        this->threads.push_back(std::thread([=]{
                            std::vector<T*> part_of_elements = {
                                elements.begin() + part * i,
                                elements.begin() + part * i + part
                            };
                            for(T* element : part_of_elements){
                                this->grid->handleAction(element);
                            }                
                        }));
                    } else {
                        this->threads.push_back(std::thread([=]{
                            std::vector<T*> part_of_elements = {
                                elements.begin() + part * i,
                                elements.end()
                            };
                            for(T* element : part_of_elements){
                                this->grid->handleAction(element);
                            }
                        }));
                    }
                }

                 for (std::thread& t : this->threads) {
                    t.join();
                }
                threads.clear();
            }
        }



        template <typename T> void draw_parallel(std::vector<T*> elements) {
            if (this->cores == 0) {
                for (T* element : elements) {
                    element->draw(this->screen);
                }
            } else {
                for (int i = 0; i < this->max_threads; i++) {
                    int part = elements.size() / this->max_threads;

                    if ((elements.size() % 2 == 0) || ((elements.size() % 2 != 0) && (i != max_threads - 1))) {
                        this->threads.push_back(std::thread([=]{
                            std::vector<T*> part_of_elements = {
                                elements.begin() + part * i,
                                elements.begin() + part * i + part
                            };
                            for(T* element : part_of_elements){
                                element->draw(this->screen);
                            }                
                        }));
                    } else {
                        this->threads.push_back(std::thread([=]{
                            std::vector<T*> part_of_elements = {
                                elements.begin() + part * i,
                                elements.end()
                            };
                            for(T* element : part_of_elements){
                                element->draw(this->screen);
                            }
                        }));
                    }
                }

                 for (std::thread& t : this->threads) {
                    t.join();
                }
                threads.clear();
            }
        }
    };
}