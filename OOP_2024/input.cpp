#include <vector>
#include <iostream>
#include "ship.hpp"
#include "input.hpp"
#include "myexception.hpp"



std::vector<int> Input::get_attack_coords()  // Функция для ввода координат атаки
{
    std::cout << "Put attack coords: ";
    std::vector<int> coords;
    int x, y;
    std::cin >> x >> y;
    if (x < 0 || y <0) throw ImproperCooordsInput(x, y);
    coords.push_back(x); coords.push_back(y);
    return coords;
}

std::vector<int> Input::get_width_and_height() // Функция для воода широты и восоты поля
{
    std::cout << "Put width and height of the field: ";
    std::vector<int> field_parametrs;
    int width, height;
    std::cin >> width >> height;
    if (width <0 || height <0) throw ImproperWidthAndHeightInput(width, height);
    field_parametrs.push_back(width); field_parametrs.push_back(height);
    return field_parametrs;
}

int Input::get_ships_number() // Функция для воода количесвта кораблей
{
    std::cout << "Put number of ships: ";
    int number;
    std::cin >> number;
    if (number <= 0) throw(ImproperShipsNumberInput(number));
    return number;
}

std::vector<int> Input::get_ships_lenghts(int ships_number) // Функция для вооад длин кораблей
{
    std::cout << "Put lenghts of the ships (max lenght = 4): ";
    std::vector<int> lenghts;
    for(size_t i=0; i<ships_number; i++)
    {
        int lenght;
        std::cin >> lenght;
        if (lenght <= 0 || lenght >= MAX_SHIP_LENGHT) throw( ImproperLenghtsInput(lenght));
        lenghts.push_back(lenght);
    }
    return lenghts;
}

std::vector<Orientation> Input::get_ships_orientations(int ships_number) // Функция для ввода ориентаций кораблей
{
    std::cout << "Put orientations of the ships \n'h' for horizontal and 'v' for vertical: ";
    std::vector<Orientation> orieantations;
    for(size_t i=0; i<ships_number; i++)
    {
        char input;
        std::cin >> input;
         (input == 'h' ? orieantations.push_back(Orientation::horisontal):
         input == 'v' ? orieantations.push_back(Orientation::vertical): throw ImproperOrieantationsInput(input) );
    }
    return orieantations;
}

std::vector<std::vector<int>> Input::get_coordinates(int ships_number) // Функция для получения координат
{
    std::cout << "Put coords of the ships: ";
    std::vector<std::vector<int>> coords;
    for(size_t i=0; i<ships_number; i++)
    {
        int x, y;
        std::cin >> x >> y;
        if (x < 0 || y < 0) throw ImproperCooordsInput(x, y);
        coords.push_back({x, y});
    }
    return coords;
}