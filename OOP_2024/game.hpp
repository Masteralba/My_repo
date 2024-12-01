#pragma once
#include <iostream>
#include "field.hpp"
#include "shipmanager.hpp"
#include "abilities.hpp"
#include "abilitiesmanager.hpp"
#include "myexception.hpp"
#include "flags.hpp"

class Game
{
    public:

    Game(Field* field, ShipManager* shipmanager, Field* enemy_field, 
    ShipManager* enemy_shipmanager, AbilitiesManager* abilitiesmanager, Flags* flags):
    field(field), shipmanager(shipmanager),  enemy_field(enemy_field), enemy_shipmanager(enemy_shipmanager),
    abilitiesmanager(abilitiesmanager), flags(flags){}

    void attack_enemy_field(int x_coord, int y_coord);

    void attack_player_field();

    void use_ability();

    void main(int width, int height, int number_of_ships, std::vector<int> lenghts,
    std::vector<Orientation> orientations, std::vector<std::vector<int>> coorditanes);

    void player_start(std::vector<std::vector<int>> coordinates_vector);

    void enemy_start(std::vector<std::vector<int>> coordinates_vector);

    void round();

    Field* field;

    Field* enemy_field;

    private:
    
    ShipManager* shipmanager;
    ShipManager* enemy_shipmanager;
    AbilitiesManager* abilitiesmanager;
    Flags* flags;
};