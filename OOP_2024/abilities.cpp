#include <iostream>
#include <random>
#include <algorithm>
#include "abilities.hpp"

void Scanner::use_skill(Field* field)
{
    std::cout << "Put coords (x, y) of the left lower corner of the square 2x2"<<std::endl;
    int x, y;
    std::cin >> x, y;
    bool ship_is_in_square = false;
    for(size_t y_coord = y; y_coord < y+SCANNER_Y_SIZE; y_coord++)
        for (size_t x_coord = x; x_coord < x+SCANNER_X_SIZE; x_coord++)  
            if (field->check_ship(x_coord, y_coord)) ship_is_in_square = true;
    if (ship_is_in_square) std::cout << "There is ship in the square" << std::endl;
    else std::cout << "There is no ship in the square" << std::endl;
}


void Shelling::use_skill(Field* field)
{
    std::vector<Ship*> ships;
    for(size_t y_coord=0; y_coord<field->get_height(); y_coord++)
    {
    for(size_t x_coord=0; x_coord<field->get_width(); x_coord++)
        {
            if (field->check_ship(x_coord, y_coord)) ships.push_back(field->get_ship(x_coord, y_coord));
        }
    }
    if (ships.size() == 0) return;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(ships.begin(), ships.end(), gen);
    int lenght = ships[0]->get_lenght();
    std::uniform_int_distribution<> distr(0,  lenght);
    int rand_segment_index = distr(gen);
    ships[0]->attack_segment(rand_segment_index);
}   