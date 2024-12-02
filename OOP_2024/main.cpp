#include <iostream>
#include <vector>

#include "ship.hpp"
#include "field.hpp"
#include "shipmanager.hpp"
#include "abilitiesmanager.hpp"
#include "myexception.hpp"

void attack_ship(ShipManager* shipmanager, Field* field, AbilitiesManager* abilitiesmanager, int x_coord, int y_coord)
{
    int destroyed_number_before = shipmanager->destroyed_number();
    try{
        field->attack_cell(x_coord, y_coord, abilitiesmanager->get_flag());
        if (abilitiesmanager->get_flag()) abilitiesmanager->change_flag();
    }catch(AttackOutOfBounds& e)
    {
        std::cout << e.what();
        return;
    }
    int destroyed_nuber_after = shipmanager->destroyed_number();
    if ( destroyed_nuber_after > destroyed_number_before) abilitiesmanager->add_ability();
}

int main()
{
    int num_of_ships = 4;
    std::vector<int>  lenghts = {1, 2, 3, 4};
    std::vector<Orientation> orientations = {Orientation::horisontal, Orientation::horisontal, Orientation::vertical,Orientation::vertical};
    ShipManager* ship_manager = new ShipManager(4, lenghts, orientations);
    AbilitiesManager* abilitiesmanager = new AbilitiesManager();
    Field* field = new Field(10, 10);
    field->place_ship(0, 0, ship_manager->get_ship(0));
    field->place_ship(5, 5, ship_manager->get_ship(2));
    try{
        field->place_ship(511, 115, ship_manager->get_ship(2));
    }catch(ShipIntersection& e) {std::cout << e.what();}
    catch(IncorrectShipPlace &e) {std::cout << e.what();}
    try{
    attack_ship(ship_manager, field, abilitiesmanager, 211, 322);
    }catch(AttackOutOfBounds& e)
    {
        std::cout << e.what();
    }
    ship_manager->show_info();
    abilitiesmanager->print_abilityes();
    try{
        abilitiesmanager->use_ability(field);
    }catch(AbilityUseInEmptyManger& e)
    {
        std::cout << e.what();
    }
    try{
        abilitiesmanager->use_ability(field);
    }catch(AbilityUseInEmptyManger& e)
    {
        std::cout << e.what();
    }
    try{
        abilitiesmanager->use_ability(field);
    }catch(AbilityUseInEmptyManger& e)
    {
        std::cout << e.what();
    }
    try{
        abilitiesmanager->use_ability(field);
    }catch(AbilityUseInEmptyManger& e)
    {
        std::cout << e.what();
    }
    return 0;
}