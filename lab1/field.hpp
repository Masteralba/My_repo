#pragma once
#include <iostream>
#include <vector>
#include "ship.hpp"

enum class CellStatus { unknown='*', empty='0', ship, outofbound};

class Field
{
private:

    class Cell
    {
    private:

        Ship* ship;
        int*  ind;
        const int coord_x, coord_y;
        CellStatus cellstatus;

    public:

        Cell(int coord_x, int coord_y):coord_x(coord_x), coord_y(coord_y),ship(nullptr),ind(nullptr),cellstatus(CellStatus::unknown){}

        ~Cell();

        void set_status(CellStatus status, Ship* ship = nullptr, int* ind = nullptr);

        void set_ship(Ship* ship);

        void set_ind(int* ind);

        CellStatus get_status();

        Ship* get_ship();

        int get_ind();
    };

    int width, height;
    std::vector< std::vector<Cell*>> cells;

public:

    Field(int width, int height);

    ~Field();

    Field(const Field& field);

    Field& operator = (const Field& field);

    Field(Field&& field);

    Field& operator = (Field&& field);

    CellStatus get_cell_status(int coord_x, int coord_y);

    void set_cell(int coord_x, int coord_y, CellStatus status, Ship* ship=nullptr, int* ind=nullptr);

    bool check_ship_intersection(int coord_x, int coord_y, int temp_coord, Orientation orientation);

    void place_ship(int coord_x, int coord_y, Ship* ship);

    void attack_cell(int coord_x, int coord_y);

    void print();

};

