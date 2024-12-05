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
    std::vector<Orientation> orientations, 
    std::vector<std::vector<int>> player_ships_coordinates, 
    std::vector<std::vector<int>> enemy_ships_coordinates,
    std::vector<std::vector<Condition>> ship_conditions);

    GameState():
    width(0), height(0), ship_number(0),
    lenghts({}), orientations({}), player_ships_coordinates({}), 
    enemy_ships_coordinates({}),ship_conditions({}){}


    int width, height, ship_number;
    std::vector<int> lenghts;
    std::vector<Orientation> orientations;
    std::vector<std::vector<Condition>> ship_conditions;

    
    Field* player_field;
    Field* enemy_field;
    std::vector<std::vector<int>> player_ships_coordinates;
    std::vector<std::vector<int>> enemy_ships_coordinates;
    ShipManager* player_shipmanager;
    ShipManager* enemy_shipmanager;
    AbilitiesManager* abilitiesmanager;
    Flags* flags;

    std::string get_data_for_output() const;

    void get_data_from_input(std::string field_data, std::string player_data, std::string enemy_data);

};


