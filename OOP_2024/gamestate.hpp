#pragma once
#include <iostream>
#include "field.hpp"
#include "shipmanager.hpp"
#include "abilities.hpp"
#include "abilitiesmanager.hpp"
#include "myexception.hpp"
#include "flags.hpp"


class GameState
{
    public:

    GameState(int width, int height, int ship_number, std::vector<int> lenghts,
    std::vector<Orientation> orientations, std::vector<std::vector<int>> coordinates, std::vector<std::vector<int>> ship_conditions):
    width(width), height(height), ship_number(ship_number),
    lenghts(lenghts), orientations(orientations), coordinates(coordinates), ship_conditions(ship_conditions){}

    GameState():
    width(0), height(0), ship_number(0),
    lenghts({}), orientations({}), coordinates({}), ship_conditions({}){}


    int width, height, ship_number;
    std::vector<int> lenghts;
    std::vector<Orientation> orientations;
    std::vector<std::vector<int>> coordinates;
    std::vector<std::vector<int>> ship_conditions;

    /*
    Field* player_field;
    Field* enemy_field;
    int ship_number;
    std::vector<std::vector<int>> player_ships_coordiantes;
    std::vector<std::vector<int>> enemy_ships_coordiantes;
    ShipManager* player_shipmanager;
    ShipManager* enemy_shipmanager;
    AbilitiesManager* abilitiesmanager;
    Flags* flags;
    */
};


