#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include "fstream"
#include "gamestate.hpp"
#include "game.hpp"

int main()
{
    std::vector<int> player_lenghts = {1, 1, 1};
    std::vector<int> enemy_lenghts = {1};
    std::vector<Orientation> player_orientations = {Orientation::horisontal, Orientation::horisontal, Orientation::vertical};
    std::vector<Orientation> enemy_orientations = {Orientation::vertical};
    std::vector<std::vector<int>> player_ships_coordinates = {{2, 2}, {5, 5}, {0, 0}};
    std::vector<std::vector<int>> enemy_ships_coordinates = {{0, 0}};
    std::vector<std::vector<Condition>> ship_conditions = {{Condition::damaged}, 
    {Condition::damaged, Condition::undamaged, Condition::destroyed}, 
    {Condition::destroyed, Condition::damaged}};

    // Ввод данных с их проверкой делает высшая сущность в виде гномика

    GameState* gamestate = new GameState(10, 10, 3, 1, player_lenghts, enemy_lenghts, player_orientations, enemy_orientations, 
    player_ships_coordinates, enemy_ships_coordinates);
    Game* game = new Game(gamestate);
    game->player_start();
    game->enemy_start();
    game->check_win();    
    
    return 0;
}