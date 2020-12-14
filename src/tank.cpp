#include "precomp.h"

namespace Tmpl8
{
Tank::Tank(float pos_x, float pos_y, allignments allignment, Sprite* tank_sprite, Sprite* smoke_sprite, Grid* grid, float tar_x, float tar_y, float collision_radius, int health, float max_speed)
    : position(pos_x, pos_y),
      allignment(allignment),
      target(tar_x, tar_y),
      health(health),
      collision_radius(collision_radius),
      max_speed(max_speed),
      force(0, 0),
      reload_time(1),
      reloaded(false),
      speed(0),
      active(true),
      current_frame(0),
      tank_sprite(tank_sprite),
      smoke_sprite(smoke_sprite),
      grid(grid){
    this->grid->add(this);

    std::cout << this->next << " " << this->previous << " " << this << std::endl;
}

Tank::~Tank()
{
}

void Tank::tick(){

    int oldCellX = (int)(this->get_position().x / Grid::CELL_SIZE);
    int oldCellY = (int)(this->get_position().y / Grid::CELL_SIZE);


    force = vec2(0.f, 0.f);
    vec2 direction = (target - position).normalized();

    speed = direction + force;
    position += speed * max_speed * 0.5f;

    if (--reload_time <= 0.0f){
        reloaded = true;
    }


    if (++current_frame > 8) current_frame = 0;

    int cellX = (int)(this->get_position().x / Grid::CELL_SIZE);
    int cellY = (int)(this->get_position().y / Grid::CELL_SIZE);

    // std::cout << cellX << " " << cellY << " " << oldCellX << " " << oldCellY << std::endl;

    if(oldCellX == cellX && oldCellY == cellY){
        return;
    }

    std::cout << "Next cell" << std::endl;

    //this->grid->remove(this);
    //this->grid->add(this);

    // // Haal de tank uit de lijst door de vorige en de volgende aan elkaar te koppelen
    if(this->previous != NULL){
        this->previous->next = this->next;
    }

    // if(this->previous != NULL){
    //     this->next->previous = this->previous;
    // }

    // if(this->previous != NULL){
    //     this->previous->next = this->next;
    // }

    if(this->next != NULL){
        this->next->previous = this->previous;
    }

    if(this->grid->cells[oldCellX][oldCellY] == this){
        this->grid->cells[oldCellX][oldCellY] = this->next;
    }

    this->grid->add(this);
}

//Start reloading timer
void Tank::reload_rocket()
{
    reloaded = false, reload_time = 200.0f;
}

void Tank::deactivate()
{
    active = false;
}

//Remove health
bool Tank::hit(int hit_value)
{
    health -= hit_value;

    if (health <= 0)
    {
        this->deactivate();
        return true;
    }

    return false;
}

//Draw the sprite with the facing based on this tanks movement direction
void Tank::draw(Surface* screen)
{
    vec2 direction = (target - position).normalized();
    tank_sprite->set_frame(((abs(direction.x) > abs(direction.y)) ? ((direction.x < 0) ? 3 : 0) : ((direction.y < 0) ? 9 : 6)) + (current_frame / 3));
    tank_sprite->draw(screen, (int)position.x - 14, (int)position.y - 18);
}

int Tank::compare_health(const Tank& other) const
{
    return ((health == other.health) ? 0 : ((health > other.health) ? 1 : -1));
}

//Add some force in a given direction
void Tank::push(vec2 direction, float magnitude)
{
    force += direction * magnitude;
}

} // namespace Tmpl8