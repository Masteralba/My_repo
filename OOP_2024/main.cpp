#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include "fstream"
#include "gamestate.hpp"

std::ostream& operator << (std::ostream &os, const GameState &gamestate)
{
    return os << gamestate.get_data_for_output();
}

std::istream& operator >> (std::istream& in, GameState &gamestate)
{
    std::string field_data, player_data, enemy_data;
    std::getline(in, field_data);
    std::getline(in, player_data);
    std::getline(in, enemy_data);
    gamestate.get_data_from_input(field_data, player_data, enemy_data);
    return in;
}

int main()
{
    std::vector<int> lenghts = {1, 2, 3};
    std::vector<Orientation> orientations = {Orientation::horisontal, Orientation::horisontal, Orientation::vertical};
    std::vector<std::vector<int>> player_ships_coordinates = {{0, 110}, {1, 2}, {5, 6}};
    std::vector<std::vector<int>> enemy_ships_coordinates = {{4, 3}, {228, 1488}, {7, 7}};
    std::vector<std::vector<Condition>> ship_conditions = {{Condition::damaged}, 
    {Condition::damaged, Condition::undamaged, Condition::destroyed}, 
    {Condition::destroyed, Condition::damaged}};
    GameState* gamestate = new GameState(10, 12, 3, lenghts, orientations, 
    player_ships_coordinates, enemy_ships_coordinates,ship_conditions);
    std::ofstream out("data.txt");
    if (out.is_open())
    {
        out << *gamestate << std::endl;
    }
    out.close();

    GameState* newgamestate = new GameState();
 
    std::ifstream in("data.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        in >> *newgamestate;
    }

    in.close();

    /*std::cout << newgamestate->width << " " << newgamestate->height <<
    " " << newgamestate->ship_number << " " << std::endl;
    for (auto elem: newgamestate->lenghts) std::cout << elem << " ";
    std::cout << std::endl;
    for (auto elem: newgamestate->orientations) std::cout << static_cast<char>(elem) << " ";
    std::cout << std::endl;
    for (auto elem: newgamestate->player_ships_coordinates) for (auto e: elem) std::cout << e << " ";
    std::cout << std::endl;
    for (auto elem: newgamestate->ship_conditions) for (auto e: elem) std::cout << static_cast<char>(e) << " ";
    std::cout << std::endl;*/
    return 0;
}