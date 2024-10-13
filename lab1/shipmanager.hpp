#pragma once
#include <vector>
#include <iostream>

#include "field.hpp"
#include "ship.hpp"

class ShipManager
{
private:
    const int num_of_ships;
    std::vector<Ship*> ships;
public:
    ShipManager(int num_of_ships, std::vector<int> lenghts, std::vector<Orientation> orientations);

    ~ShipManager();

    Ship* get_ship(int ind);
    
    void show_info();
};