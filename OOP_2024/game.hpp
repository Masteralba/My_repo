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

    void main();

    void player_start();

    void enemy_start();

    void round(int coord_x, int coord_y, bool ability_flag=false);

    GameState* gamestate;

    private:
    
    void player_tern(int coord_x, int coord_y, bool ability_flag=false);

    void enemy_tern();

    void attack_enemy_field(int x_coord, int y_coord);

    void attack_player_field();

    void use_ability();
    
};