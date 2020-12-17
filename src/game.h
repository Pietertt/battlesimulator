#pragma once

namespace Tmpl8
{
//forward declarations
class Tank;
class Rocket;
class Smoke;
class Particle_beam;
class Surface;
class Sprite;

class Game
{
  public:
    void set_target(Surface* surface) { screen = surface; }
    void init();
    void shutdown();
    void update(float deltaTime);
    void draw();
    void tick(float deltaTime);
    void insertion_sort_tanks_health(const std::vector<Tank>& original, std::vector<const Tank*>& sorted_tanks, int begin, int end);
    void measure_performance();

    Tank& find_closest_enemy(Tank& current_tank);

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

        vector<Tank*> tanks;
    vector<Object*> rockets;
    vector<Object*> beams;

    Surface* rocket_red_img = new Surface("/Users/pieterboersma/Desktop/battlesimulator/assets/Rocket_Proj2.png");
    Surface* rocket_blue_img = new Surface("/Users/pieterboersma/Desktop/battlesimulator/assets/Rocket_Blue_Proj2.png");
    
    Sprite rocket_red = Sprite(this->rocket_red_img, 12);
    Sprite rocket_blue = Sprite(this->rocket_blue_img, 12);

  private:
    Surface* screen;
    

    Grid grid = Grid(this);


    
    vector<Explosion> explosions;
    vector<Smoke> smokes;

    Font* frame_count_font;
    long long frame_count = 0;

    bool lock_update = false;
};

}; // namespace Tmpl8