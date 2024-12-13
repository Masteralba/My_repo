#pragma once
#include <iostream>
#include "abilities.hpp"
#include "abilitiesmanager.hpp"
#include "field.hpp"

class AbilityUseInEmptyManger
{
    public:
    AbilitiesManager* abilitiesmanager;
    AbilityUseInEmptyManger(AbilitiesManager* abilitiesmanager): abilitiesmanager(abilitiesmanager){}

    std::string what();
};

class ShipExceptions
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

    std::string what();
};

class CellOutOfBounds: public ShipExceptions
{
    public:
    
    CellOutOfBounds(Field* field, int coord_x, int coord_y): ShipExceptions(field, coord_x, coord_y){}

    std::string what();
};

class SetCellOutOfBounds: public ShipExceptions
{
    public:
    
    SetCellOutOfBounds(Field* field, int coord_x, int coord_y): ShipExceptions(field, coord_x, coord_y){}

    std::string what();
};

class ShipIntersection : ShipExceptions
{
    public:

    ShipIntersection(Field* field, int coord_x, int coord_y): ShipExceptions(field, coord_x, coord_y){};

    std::string  what();
};

class IncorrectShipPlace : ShipExceptions
{
    public:

    Orientation orientation;
    int lenght;

    IncorrectShipPlace(Field* field, int coord_x, int coord_y, Orientation orientation, int lenght): ShipExceptions(field, coord_x, coord_y)
    , orientation(orientation), lenght(lenght){};

    std::string  what();
};

class FileWasChanged
{
    public:

    FileWasChanged(std::string filename):filename(filename){}

    std::string what();

    private:

    std::string filename = "";
};


class ImproperCommandInput
{
    public:

    ImproperCommandInput(char input):input(input){}

    std::string what();

    private:

    char input;
};

class ImproperCooordsInput
{
    public:

    ImproperCooordsInput(int x, int y):x(x), y(y){}

    std::string what();

    private:

    int x, y;
};


class ImproperWidthAndHeightInput
{
    public:

    ImproperWidthAndHeightInput(int width, int height):width(width), height(height){}

    std::string what();

    private:

    int width, height;
};


class ImproperLenghtsInput
{
    public:

    ImproperLenghtsInput(int lenght):lenght(lenght){}

    std::string what();

    private:

    int lenght;
};


class ImproperShipsNumberInput
{
    public:

    ImproperShipsNumberInput(int num):num(num){}

    std::string what();

    private:

    int num;
};


class ImproperOrieantationsInput
{
    public:

    ImproperOrieantationsInput(char input):input(input){}

    std::string what();

    private:

    char input;
};
