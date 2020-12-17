#include "precomp.h" // include (only) this in every .cpp file

#define NUM_TANKS_BLUE 500
#define NUM_TANKS_RED 500

#define TANK_MAX_HEALTH 1000
#define ROCKET_HIT_VALUE 60
#define PARTICLE_BEAM_HIT_VALUE 50

#define TANK_MAX_SPEED 1.5

#define HEALTH_BARS_OFFSET_X 0
#define HEALTH_BAR_HEIGHT 70
#define HEALTH_BAR_WIDTH 1
#define HEALTH_BAR_SPACING 0

#define MAX_FRAMES 2000

//Global performance timer
#define REF_PERFORMANCE 73466 //UPDATE THIS WITH YOUR REFERENCE PERFORMANCE (see console after 2k frames)
static timer perf_timer;
static float duration;

//Load sprite files and initialize sprites
static Surface* background_img = new Surface("/Users/pieterboersma/Desktop/battlesimulator/assets/Background_Grass.png");
static Surface* tank_red_img = new Surface("/Users/pieterboersma/Desktop/battlesimulator/assets/Tank_Proj2.png");
static Surface* tank_blue_img = new Surface("/Users/pieterboersma/Desktop/battlesimulator/assets/Tank_Blue_Proj2.png");
static Surface* rocket_red_img = new Surface("/Users/pieterboersma/Desktop/battlesimulator/assets/Rocket_Proj2.png");
static Surface* rocket_blue_img = new Surface("/Users/pieterboersma/Desktop/battlesimulator/assets/Rocket_Blue_Proj2.png");
static Surface* particle_beam_img = new Surface("/Users/pieterboersma/Desktop/battlesimulator/assets/Particle_Beam.png");
static Surface* smoke_img = new Surface("/Users/pieterboersma/Desktop/battlesimulator/assets/Smoke.png");
static Surface* explosion_img = new Surface("/Users/pieterboersma/Desktop/battlesimulator/assets/Explosion.png");

static Sprite background(background_img, 1);
static Sprite tank_red(tank_red_img, 12);
static Sprite tank_blue(tank_blue_img, 12);
static Sprite rocket_red(rocket_red_img, 12);
static Sprite rocket_blue(rocket_blue_img, 12);
static Sprite smoke(smoke_img, 4);
static Sprite explosion(explosion_img, 9);
static Sprite particle_beam_sprite(particle_beam_img, 3);

const static vec2 tank_size(14, 18);
const static vec2 rocket_size(25, 24);

const static float tank_radius = 8.5f;
const static float rocket_radius = 10.f;

ActionVisitor visitor = ActionVisitor();

// -----------------------------------------------------------
// Initialize the application
// -----------------------------------------------------------
void Game::init(){
    this->grid.test(&visitor);
    visitor.add(this);
    frame_count_font = new Font("/Users/pieterboersma/Desktop/battlesimulator/assets/digital_small.png", "ABCDEFGHIJKLMNOPQRSTUVWXYZ:?!=-0123456789.");

    tanks.reserve(NUM_TANKS_BLUE + NUM_TANKS_RED);

    uint rows = (uint)sqrt(NUM_TANKS_BLUE + NUM_TANKS_RED);
    uint max_rows = 12;

    float start_blue_x = tank_size.x + 10.0f;
    float start_blue_y = tank_size.y + 300.0f;

    float start_red_x = 980.0f;
    float start_red_y = 100.0f;

    float spacing = 15.0f;

    //Spawn blue tanks
    for (int i = 0; i < NUM_TANKS_BLUE; i++)
    {
        Tank* tank = new Tank(start_blue_x + ((i % max_rows) * spacing), start_blue_y + ((i / max_rows) * spacing), BLUE, &tank_blue, &smoke, 1200, 600, tank_radius, TANK_MAX_HEALTH, TANK_MAX_SPEED);
        tanks.push_back(tank);
    }
    //Spawn red tanks
    for (int i = 0; i < NUM_TANKS_RED; i++)
    {
        Tank* tank = new Tank(start_red_x + ((i % max_rows) * spacing), start_red_y + ((i / max_rows) * spacing), RED, &tank_red, &smoke, 80, 80, tank_radius, TANK_MAX_HEALTH, TANK_MAX_SPEED);
        tanks.push_back(tank);
    }

    for(Tank* tank : tanks){
        grid.add(tank);
    }

    Beam* beam1 = new Beam(vec2(SCRWIDTH / 2, SCRHEIGHT / 2), vec2(100, 50), &particle_beam_sprite, PARTICLE_BEAM_HIT_VALUE);
    Beam* beam2 = new Beam(vec2(80, 80), vec2(100, 50), &particle_beam_sprite, PARTICLE_BEAM_HIT_VALUE);
    Beam* beam3 = new Beam(vec2(1200, 600), vec2(100, 50), &particle_beam_sprite, PARTICLE_BEAM_HIT_VALUE);

    beams.push_back(beam1);
    beams.push_back(beam2);
    beams.push_back(beam3);
}

// -----------------------------------------------------------
// Close down application
// -----------------------------------------------------------
void Game::shutdown(){
    std::cout << "Shutdown!" << std::endl;
}

// -----------------------------------------------------------
// Iterates through all tanks and returns the closest enemy tank for the given tank
// -----------------------------------------------------------
// Tank& Game::find_closest_enemy(Tank& current_tank){
//     float closest_distance = numeric_limits<float>::infinity();
//     int closest_index = 0;

//     for (int i = 0; i < tanks.size(); i++){
//         if (tanks.at(i).allignment != current_tank.allignment && tanks.at(i).active){
//             float sqrDist = fabsf((tanks.at(i).get_position() - current_tank.get_position()).sqr_length());
//             if (sqrDist < closest_distance){
//                 closest_distance = sqrDist;
//                 closest_index = i;
//             }
//         }
//     }

//     return tanks.at(closest_index);
// }

// -----------------------------------------------------------
// Update the game state:
// Move all objects
// Update sprite frames
// Collision detection
// Targeting etc..
// -----------------------------------------------------------
void Game::update(float deltaTime){
    //Update tanks

    for(Tank* tank : this->tanks){
        if(tank->active){
            this->grid.handleAction(tank);
        }
    }
    

    for(Object* rocket : this->rockets){
        this->grid.handleAction(rocket);
    }

    for (Object* beam : this->beams){
        this->grid.handleAction(beam);
    }

    //Remove exploded rockets with remove erase idiom
    //rockets.erase(std::remove_if(rockets.begin(), rockets.end(), [](const Object& rocket) { return !rocket.active; }), rockets.end());


    //Update smoke plumes
    for (Smoke& smoke : smokes){
        smoke.tick();
    }


    //Update explosion sprites and remove when done with remove erase idiom
    for (Explosion& explosion : explosions){
        explosion.tick();
    }

    explosions.erase(std::remove_if(explosions.begin(), explosions.end(), [](const Explosion& explosion) { return explosion.done(); }), explosions.end());
}

void Game::draw(){
    // clear the graphics window
    screen->clear(0);

    //Draw background
    background.draw(screen, 0, 0);

    //Draw sprites
    for (int i = 0; i < NUM_TANKS_BLUE + NUM_TANKS_RED; i++){
        tanks.at(i)->draw(screen);

        //vec2 tPos = tanks.at(i).get_position();
        // tread marks
        //if ((tPos.x >= 0) && (tPos.x < SCRWIDTH) && (tPos.y >= 0) && (tPos.y < SCRHEIGHT))
            //background.get_buffer()[(int)tPos.x + (int)tPos.y * SCRWIDTH] = sub_blend(background.get_buffer()[(int)tPos.x + (int)tPos.y * SCRWIDTH], 0x808080);
    }

    for (Object* rocket : rockets){
        rocket->draw(screen);
    }

    for (Smoke& smoke : smokes){
        smoke.draw(screen);
    }

    for (Object* beam : this->beams){
        beam->draw(screen);
    }

    for (Explosion& explosion : explosions){
        explosion.draw(screen);
    }

    // //Draw sorted health bars
    // for (int t = 0; t < 2; t++){
    //     const int NUM_TANKS = ((t < 1) ? NUM_TANKS_BLUE : NUM_TANKS_RED);

    //     const int begin = ((t < 1) ? 0 : NUM_TANKS_BLUE);
    //     std::vector<const Tank*> sorted_tanks;
    //     //insertion_sort_tanks_health(tanks, sorted_tanks, begin, begin + NUM_TANKS);

    //     for (int i = 0; i < NUM_TANKS; i++){
    //         int health_bar_start_x = i * (HEALTH_BAR_WIDTH + HEALTH_BAR_SPACING) + HEALTH_BARS_OFFSET_X;
    //         int health_bar_start_y = (t < 1) ? 0 : (SCRHEIGHT - HEALTH_BAR_HEIGHT) - 1;
    //         int health_bar_end_x = health_bar_start_x + HEALTH_BAR_WIDTH;
    //         int health_bar_end_y = (t < 1) ? HEALTH_BAR_HEIGHT : SCRHEIGHT - 1;

    //         screen->bar(health_bar_start_x, health_bar_start_y, health_bar_end_x, health_bar_end_y, REDMASK);
    //         screen->bar(health_bar_start_x, health_bar_start_y + (int)((double)HEALTH_BAR_HEIGHT * (1 - ((double)sorted_tanks.at(i)->health / (double)TANK_MAX_HEALTH))), health_bar_end_x, health_bar_end_y, GREENMASK);
    //     }
    // }
}

// -----------------------------------------------------------
// Sort tanks by health value using insertion sort
// -----------------------------------------------------------
void Tmpl8::Game::insertion_sort_tanks_health(const std::vector<Tank>& original, std::vector<const Tank*>& sorted_tanks, int begin, int end){
    const int NUM_TANKS = end - begin;
    sorted_tanks.reserve(NUM_TANKS);
    sorted_tanks.emplace_back(&original.at(begin));

    for (int i = begin + 1; i < (begin + NUM_TANKS); i++){
        const Tank& current_tank = original.at(i);

        for (int s = (int)sorted_tanks.size() - 1; s >= 0; s--){
            const Tank* current_checking_tank = sorted_tanks.at(s);

            if ((current_checking_tank->compare_health(current_tank) <= 0)){
                sorted_tanks.insert(1 + sorted_tanks.begin() + s, &current_tank);
                break;
            }

            if (s == 0){
                sorted_tanks.insert(sorted_tanks.begin(), &current_tank);
                break;
            }
        }
    }
}

// -----------------------------------------------------------
// When we reach MAX_FRAMES print the duration and speedup multiplier
// Updating REF_PERFORMANCE at the top of this file with the value
// on your machine gives you an idea of the speedup your optimizations give
// -----------------------------------------------------------
void Tmpl8::Game::measure_performance(){
    char buffer[128];
    if (frame_count >= MAX_FRAMES){
        if (!lock_update){
            duration = perf_timer.elapsed();
            cout << "Duration was: " << duration << " (Replace REF_PERFORMANCE with this value)" << endl;
            lock_update = true;
        }

        frame_count--;
    }

    if (lock_update){
        screen->bar(420, 170, 870, 430, 0x030000);
        int ms = (int)duration % 1000, sec = ((int)duration / 1000) % 60, min = ((int)duration / 60000);
        sprintf(buffer, "%02i:%02i:%03i", min, sec, ms);
        frame_count_font->centre(screen, buffer, 200);
        sprintf(buffer, "SPEEDUP: %4.1f", REF_PERFORMANCE / duration);
        frame_count_font->centre(screen, buffer, 340);
    }
}

// -----------------------------------------------------------
// Main application tick function
// -----------------------------------------------------------
void Game::tick(float deltaTime){
    if (!lock_update){
        update(deltaTime);
    }
    draw();

    measure_performance();

    // print something in the graphics window
    //screen->Print("hello world", 2, 2, 0xffffff);

    // print something to the text window
    //cout << "This goes to the console window." << std::endl;

    //Print frame count
    frame_count++;
    string frame_count_string = "FRAME: " + std::to_string(frame_count);
    frame_count_font->print(screen, frame_count_string.c_str(), 350, 580);
}
