#pragma once
#include <iostream>
#include "field.hpp"
#include "shipmanager.hpp"
#include "abilities.hpp"
#include "abilitiesmanager.hpp"
#include "myexception.hpp"
#include "flags.hpp"
#include "gamestate.hpp"

class Game
{
    public:

    Game(GameState* gamestate):gamestate(gamestate){}

    GameState* get_gamestate(){return this->gamestate;}

    void player_start();

    void enemy_start();

    void round(int coord_x, int coord_y, bool ability_flag=false);

    void check_win();

    void save(const char* filename);

    void load(const char* filename);

    GameState* gamestate;

    private:
    
    void player_tern(int coord_x, int coord_y, bool ability_flag=false);

    void enemy_tern();

    void attack_enemy_field(int x_coord, int y_coord);

    void attack_player_field();

    void use_ability();
    
};