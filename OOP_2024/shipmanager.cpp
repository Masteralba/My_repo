#include <vector>
#include <iostream>

#include "field.hpp"
#include "ship.hpp"
#include "shipmanager.hpp"

ShipManager::ShipManager(int num_of_ships, std::vector<int> lenghts, std::vector<Orientation> orientations):num_of_ships(num_of_ships)
{
    for(size_t lenght_iterator=0; lenght_iterator<num_of_ships; lenght_iterator++)
    {
        ships.push_back(new Ship(lenghts[lenght_iterator], orientations[lenght_iterator]));
    }
}

ShipManager::~ShipManager()
{
    for(size_t length_iterator=0; length_iterator< num_of_ships; length_iterator++)
        delete ships[length_iterator];
}

Ship* ShipManager::get_ship(int ind)
{
    if ( ind < 0 || ind >= this->num_of_ships)
    {
        std::cerr << "Invalid index in ShipManager::get_ship" << std::endl;
        exit(1);
    }
    return this->ships[ind];
}
    
void ShipManager::show_info() 
{
    for(size_t index_iterator=0; index_iterator<this->num_of_ships; index_iterator++) this->ships[index_iterator]->print_segments();
    std::cout << std::endl;
}    
