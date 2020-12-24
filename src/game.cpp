#include "precomp.h" // include (only) this in every .cpp file

#define NUM_TANKS_BLUE 10
#define NUM_TANKS_RED 10

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

Game::Game(){

}

void Game::insert_grid(Grid* grid){
    this->grid = grid;
}

// -----------------------------------------------------------
// Initialize the application
// -----------------------------------------------------------
void Game::init()
{
    frame_count_font = new Font("/Users/pieterboersma/Desktop/battlesimulator/assets/digital_small.png", "ABCDEFGHIJKLMNOPQRSTUVWXYZ:?!=-0123456789.");

    tanks.reserve(NUM_TANKS_BLUE + NUM_TANKS_RED);

    uint rows = (uint)sqrt(NUM_TANKS_BLUE + NUM_TANKS_RED);
    uint max_rows = 12;

    float start_blue_x = tank_size.x + 10.0f;
    float start_blue_y = tank_size.y + 380.0f;

    float start_red_x = 980.0f;
    float start_red_y = 100.0f;

    float spacing = 15.0f;

    //Spawn blue tanks
    for (int i = 0; i < NUM_TANKS_BLUE; i++)
    {
        Tank* tank = new Tank(start_blue_x + ((i % max_rows) * spacing), start_blue_y + ((i / max_rows) * spacing), BLUE, &tank_blue, &smoke, this->grid, 1200, 600, tank_radius, TANK_MAX_HEALTH, TANK_MAX_SPEED);
        this->tanks.push_back(tank);
    }
    //Spawn red tanks
    for (int i = 0; i < NUM_TANKS_RED; i++)
    {
        Tank* tank = new Tank(start_red_x + ((i % max_rows) * spacing), start_red_y + ((i / max_rows) * spacing), RED, &tank_red, &smoke, this->grid, 80, 80, tank_radius, TANK_MAX_HEALTH, TANK_MAX_SPEED);
        tanks.push_back(tank);
    }

    for(Tank* tank : this->tanks){
        this->grid->add(tank);
    }
    Particle_beam* beam1 = new Particle_beam(vec2(SCRWIDTH / 2, SCRHEIGHT / 2), vec2(100, 50), &particle_beam_sprite, PARTICLE_BEAM_HIT_VALUE);
    Particle_beam* beam2 = new Particle_beam(vec2(80, 80), vec2(100, 50), &particle_beam_sprite, PARTICLE_BEAM_HIT_VALUE);
    Particle_beam* beam3 = new Particle_beam(vec2(1200, 600), vec2(100, 50), &particle_beam_sprite, PARTICLE_BEAM_HIT_VALUE);
    particle_beams.push_back(beam1);
    particle_beams.push_back(beam2);
    particle_beams.push_back(beam3);
}

// -----------------------------------------------------------
// Close down application
// -----------------------------------------------------------
void Game::shutdown()
{
}

// -----------------------------------------------------------
// Iterates through all tanks and returns the closest enemy tank for the given tank
// -----------------------------------------------------------
Tank* Game::find_closest_enemy(Tank* current_tank)
{
    float closest_distance = numeric_limits<float>::infinity();
    int closest_index = 0;

    for (int i = 0; i < tanks.size(); i++)
    {
        if (tanks.at(i)->allignment != current_tank->allignment && tanks.at(i)->active)
        {
            float sqrDist = fabsf((tanks.at(i)->get_position() - current_tank->get_position()).sqr_length());
            if (sqrDist < closest_distance)
            {
                closest_distance = sqrDist;
                closest_index = i;
            }
        }
    }

    return tanks.at(closest_index);
}

// -----------------------------------------------------------
// Update the game state:
// Move all objects
// Update sprite frames
// Collision detection
// Targeting etc..
// -----------------------------------------------------------
void Game::update(float deltaTime)
{
    //Update tanks
    for (Tank* tank : tanks)
    {
        if (tank->active)
        {
            //Check tank collision and nudge tanks away from each other
            for (Tank* oTank : tanks)
            {
                if (tank == oTank) continue;
                
                vec2 dir = tank->get_position() - oTank->get_position();
                float dirSquaredLen = dir.sqr_length();

                float colSquaredLen = (tank->get_collision_radius() + oTank->get_collision_radius());
                colSquaredLen *= colSquaredLen;

                if (dirSquaredLen < colSquaredLen)
                {
                    tank->push(dir.normalized(), 1.f);
                }
            }

            //Move tanks according to speed and nudges (see above) also reload
            tank->tick();
            this->grid->move(tank);

            //Shoot at closest target if reloaded
            if (tank->rocket_reloaded())
            {
                Tank* target = find_closest_enemy(tank);

                Rocket* rocket = new Rocket(tank->position, (target->get_position() - tank->position).normalized() * 3, 10.0f, tank->allignment, ((tank->allignment == RED) ? &rocket_red : &rocket_blue));
                rockets.push_back(rocket);

                tank->reload_rocket();
            }
        }
    }

    //Update smoke plumes
    for (Smoke& smoke : smokes)
    {
        smoke.tick();
    }

    //Update rockets
    for (Rocket* rocket : rockets) {
        this->grid->handleAction(rocket);        
    }

    for(Particle_beam* beam : this->particle_beams){
        this->grid->handleAction(beam);
    }

    //Remove exploded rockets with remove erase idiom
    rockets.erase(std::remove_if(rockets.begin(), rockets.end(), [](const Rocket* rocket) { return !rocket->active; }), rockets.end());

    //Update explosion sprites and remove when done with remove erase idiom
    for (Explosion& explosion : explosions)
    {
        explosion.tick();
    }

    explosions.erase(std::remove_if(explosions.begin(), explosions.end(), [](const Explosion& explosion) { return explosion.done(); }), explosions.end());
}




























std::vector<Tank*>& Game::merge_sort_tanks_health(std::vector<Tank*>& unsorted, std::vector<Tank*>& sorted){

    if(unsorted.size() == 1){
        return unsorted;
    }

    std::vector<Tank*> a;
    std::vector<Tank*> b;

    std::cout << "Unsorted size " << unsorted.size() << std::endl;
    if(unsorted.size() % 2 == 0){
        int count = unsorted.size() / 2;
        std::cout << "Count is " << count << std::endl;
        a = std::vector<Tank*>(unsorted.begin(), unsorted.begin() + count);
        b = std::vector<Tank*>(unsorted.end() - count, unsorted.end());

    } else {
        int middle = unsorted.size() / 2;
        std::cout << "Middle is " << middle << std::endl;
        a = std::vector<Tank*>(unsorted.begin(), unsorted.begin() + middle);
        b = std::vector<Tank*>(unsorted.end() - middle, unsorted.end());
    }

    a = this->merge_sort_tanks_health(a, sorted);
    for(Tank* tank : a){
        std::cout << tank << " ";
    }
    std::cout << std::endl;    std::cout << std::endl;


    b = this->merge_sort_tanks_health(b, sorted);
        for(Tank* tank : b){
        std::cout << tank << " ";
    }
    std::cout << std::endl;    std::cout << std::endl;

    return this->merge_tanks_health(a, b, sorted);

    //return unsorted;

    //return unsorted;
}





















std::vector<Tank*>& Game::merge_tanks_health(std::vector<Tank*> a, std::vector<Tank*> b, std::vector<Tank*>& sorted){
    std::cout << "Merge called" << std::endl;
    if(a.size() == 0){
        std::cout << "List A is empty, next one" << std::endl;
        for(Tank* tank : b){
            sorted.push_back(tank);
        }
        return sorted;
    }

    if(b.size() == 0){
        std::cout << "List B is empty, next one" << std::endl;
        for(Tank* tank : a){
            sorted.push_back(tank);
        }

        std::cout << a.size() << " " << b.size() << std::endl;
        return sorted;
    }

    if(a.at(0)->compare_health(b.at(0)) >= 0){
        std::cout << "A tank with " << a.at(0) << a.at(0)->health << " before a tank with " << b.at(0)->health << std::endl;
        sorted.push_back(a.at(0));
        a.erase(a.begin());
    } else {
        std::cout << "A tank with " << b.at(0) << b.at(0)->health << " before a tank with " << a.at(0)->health << std::endl;
        sorted.push_back(b.at(0));
        b.erase(b.begin());
    }

    //return sorted;

    std::cout << a.size() << " " << b.size() << std::endl;
        for(Tank* tank : a){
        std::cout << tank << " ";
    }
    std::cout << std::endl;    std::cout << std::endl;

    for(Tank* tank : b){
        std::cout << tank << " ";
    }
    std::cout << std::endl;    std::cout << std::endl;

    std::vector<Tank*> test = this->merge_tanks_health(a, b, sorted);
    
    for(Tank* tank : test){
        sorted.push_back(tank);
    }

    // for(Tank* tank : sorted){
    //     std::cout << tank->health << " ";
    // }

    //std::cout << std::endl; 

    return sorted;

    //return a;
}























void Game::draw()
{
    // clear the graphics window
    screen->clear(0);

    //Draw background
    background.draw(screen, 0, 0);

    //Draw sprites
    for (int i = 0; i < NUM_TANKS_BLUE + NUM_TANKS_RED; i++)
    {
        tanks.at(i)->draw(screen);

        vec2 tPos = tanks.at(i)->get_position();
        // tread marks
        if ((tPos.x >= 0) && (tPos.x < SCRWIDTH) && (tPos.y >= 0) && (tPos.y < SCRHEIGHT))
            background.get_buffer()[(int)tPos.x + (int)tPos.y * SCRWIDTH] = sub_blend(background.get_buffer()[(int)tPos.x + (int)tPos.y * SCRWIDTH], 0x808080);
    }

    for (Rocket* rocket : rockets)
    {
        rocket->draw(screen);
    }

    for (Smoke& smoke : smokes)
    {
        smoke.draw(screen);
    }

    for (Particle_beam* particle_beam : particle_beams)
    {
        particle_beam->draw(screen);
    }

    for (Explosion& explosion : explosions)
    {
        explosion.draw(screen);
    }

    //std::cout << sorted_blue.size() << " " << result_red.size() << std::endl;

    // // for(Tank* tank : result_red){
    // //     std::cout << tank->health << std::endl;
    // // }

    // // std::cout << std::endl;

    // for(int i = 0; i < 2; i++){
    //     for(int n = 0; n < NUM_TANKS_BLUE; n++){
    //         int health_bar_start_x = i * (HEALTH_BAR_WIDTH + HEALTH_BAR_SPACING) + HEALTH_BARS_OFFSET_X;
    //         int health_bar_start_y = (i < 1) ? 0 : (SCRHEIGHT - HEALTH_BAR_HEIGHT) - 1;
    //         int health_bar_end_x = health_bar_start_x + HEALTH_BAR_WIDTH;
    //         int health_bar_end_y = (i < 1) ? HEALTH_BAR_HEIGHT : SCRHEIGHT - 1; 

    //         screen->bar(health_bar_start_x, health_bar_start_y, health_bar_end_x, health_bar_end_y, REDMASK);
    //         screen->bar(health_bar_start_x, health_bar_start_y + (int)((double)HEALTH_BAR_HEIGHT * (1 - (n == 0) ? (double)sorted_blue.at(n)->health : (double)sorted_red.at(n)->health / (double)TANK_MAX_HEALTH)), health_bar_end_x, health_bar_end_y, GREENMASK);
    //     }
    // }




    // std::vector<Tank*>::const_iterator blue_start = this->tanks.begin();
    // std::vector<Tank*>::const_iterator blue_end = this->tanks.begin() + NUM_TANKS_BLUE;
    // std::vector<Tank*>::const_iterator red_start = this->tanks.begin() + NUM_TANKS_BLUE;
    // std::vector<Tank*>::const_iterator red_end = this->tanks.end();
    // std::vector<Tank*> result_blue(blue_start, blue_end);
    // std::vector<Tank*> result_red(red_start, red_end);

    // std::vector<Tank*> sorted_blue = this->merge_sort_tanks_health(result_blue);
    // std::vector<Tank*> sorted_red = this->merge_sort_tanks_health(result_red);


    // //Draw sorted health bars
    for (int t = 0; t < 2; t++)
    {
        const int NUM_TANKS = ((t < 1) ? NUM_TANKS_BLUE : NUM_TANKS_RED);

        const std::vector<Tank*>::const_iterator begin = ((t < 1) ? this->tanks.begin() : this->tanks.begin() + NUM_TANKS_BLUE);
        const std::vector<Tank*>::const_iterator end = ((t < 1 ? this->tanks.begin() + NUM_TANKS_BLUE : this->tanks.end()));


        std::vector<Tank*> sorted_tanks;
        std::vector<Tank*> unsorted_tanks(begin, end);

        std::vector<Tank*> g(((t == 0) ? tanks.begin() : tanks.begin() + NUM_TANKS_BLUE), ((t == 0) ? tanks.begin() + NUM_TANKS_BLUE : tanks.end()));

        this->merge_sort_tanks_health(unsorted_tanks, sorted_tanks);

        std::cout << "Finished" << std::endl;

        for(Tank* tank : sorted_tanks){
            //std::cout << tank->health << " " << sorted_tanks.size() << std::endl;
        }

        //std::cout << std::endl;

        //insertion_sort_tanks_health(tanks, sorted_tanks, begin, begin + NUM_TANKS);

        for (int i = 0; i < NUM_TANKS; i++)
        {
            int health_bar_start_x = i * (HEALTH_BAR_WIDTH + HEALTH_BAR_SPACING) + HEALTH_BARS_OFFSET_X;
            int health_bar_start_y = (t < 1) ? 0 : (SCRHEIGHT - HEALTH_BAR_HEIGHT) - 1;
            int health_bar_end_x = health_bar_start_x + HEALTH_BAR_WIDTH;
            int health_bar_end_y = (t < 1) ? HEALTH_BAR_HEIGHT : SCRHEIGHT - 1;

            screen->bar(health_bar_start_x, health_bar_start_y, health_bar_end_x, health_bar_end_y, REDMASK);
            screen->bar(health_bar_start_x, health_bar_start_y + (int)((double)HEALTH_BAR_HEIGHT * (1 - ((double)g.at(i)->health / (double)TANK_MAX_HEALTH))), health_bar_end_x, health_bar_end_y, GREENMASK);
        }
    }
}
























// -----------------------------------------------------------
// Sort tanks by health value using insertion sort
// -----------------------------------------------------------
void Tmpl8::Game::insertion_sort_tanks_health(std::vector<Tank*>& original, std::vector<Tank*>& sorted_tanks, int begin, int end) {
    const int NUM_TANKS = end - begin;
    sorted_tanks.reserve(NUM_TANKS);
    sorted_tanks.emplace_back(original.at(begin));

    for (int i = begin + 1; i < (begin + NUM_TANKS); i++) {
        Tank* current_tank = original.at(i);

        for (int s = (int)sorted_tanks.size() - 1; s >= 0; s--) {
            Tank* current_checking_tank = sorted_tanks.at(s);

            if ((current_checking_tank->compare_health(current_tank) <= 0)) {
                sorted_tanks.insert(1 + sorted_tanks.begin() + s, current_tank);
                break;
            }

            if (s == 0) {
                sorted_tanks.insert(sorted_tanks.begin(), current_tank);
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
void Tmpl8::Game::measure_performance()
{
    char buffer[128];
    if (frame_count >= MAX_FRAMES)
    {
        if (!lock_update)
        {
            duration = perf_timer.elapsed();
            cout << "Duration was: " << duration << " (Replace REF_PERFORMANCE with this value)" << endl;
            lock_update = true;
        }

        frame_count--;
    }

    if (lock_update)
    {
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
void Game::tick(float deltaTime)
{
    if (!lock_update)
    {
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
