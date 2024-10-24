#include <iostream>
#include <vector>

#include "ship.hpp"
#include "field.hpp"
#include "shipmanager.hpp"

int main()
{
    int num_of_ships = 4;
    std::vector<int>  lenghts = {1, 2, 3, 4};
    std::vector<Orientation> orientations = {Orientation::horisontal, Orientation::horisontal, Orientation::vertical,Orientation::vertical};
    ShipManager ship_manager(4, lenghts, orientations);
    Field field(10, 10);
    field.place_ship(0, 0, ship_manager.get_ship(0));
    field.place_ship(5, 5, ship_manager.get_ship(2));
    field.attack_cell(5, 5);
    ship_manager.show_info();
    field.print();
    return 0;
}