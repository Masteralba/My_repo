#pragma once
#include <iostream>
#include "abilities.hpp"
#include "abilitiesmanager.hpp"
#include "field.hpp"

class AbilityUseInEmptyManger: public std::exception
{
    public:
    AbilitiesManager* abilitiesmanager;
    AbilityUseInEmptyManger(AbilitiesManager* abilitiesmanager): abilitiesmanager(abilitiesmanager){}

    const char* what() const noexcept override
    {
    std::string msg = "Empty Abilities Manager\n\0";
    return msg.c_str();
    }
};

class ShipExceptions : public std::exception
{
    public:
    Field* field;
    int coord_x, coord_y;
    ShipExceptions(Field* field,int coord_x, int coord_y):field(field), coord_x(coord_x), coord_y(coord_y){}

};

class AttackOutOfBounds: public ShipExceptions
{
    public:
    
    AttackOutOfBounds(Field* field, int coord_x, int coord_y): ShipExceptions(field, coord_x, coord_y){}

    const char* what() const noexcept override
    {
    std::string msg = "Attack in field, with height" + std::to_string(field->get_height()) +
    " with width" + std::to_string(field->get_width())+
    "Attack coords are :\n" + std::to_string(coord_x) + " " + std::to_string(coord_y) + "\n\0";
    return msg.c_str();
    }
};

class ShipIntersection: public ShipExceptions
{
    public:

    ShipIntersection(Field* field, int coord_x, int coord_y): ShipExceptions(field, coord_x, coord_y){}

    const char* what() const noexcept override
    {
    std::string msg = "Shipintersection in field, with height" + std::to_string(field->get_height()) +
    " with width" + std::to_string(field->get_width())+
    "Ship place coords are :\n" + std::to_string(coord_x) + " " + std::to_string(coord_y) + "\n\0";
    return msg.c_str();
    }
};