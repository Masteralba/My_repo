#pragma once
#include <iostream>
#include <vector>
#include "ship.hpp"

#define VOID_INDEX -1

enum class CellStatus { unknown='*', empty='0', ship, outofbound};

class Field
{
private:

    class Cell
    {
    private:

        Ship* ship;
        int  ind;
        CellStatus cellstatus;

    public:

        Cell(int coord_x, int coord_y):ship(nullptr),ind(VOID_INDEX),cellstatus(CellStatus::unknown){}

        void set_status(CellStatus status);

        void set_ship(Ship* ship, int ind);

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

    void set_cell(int coord_x, int coord_y, Ship* ship=nullptr, int ind=VOID_INDEX);

    bool check_ship_intersection(int coord_x, int coord_y, int temp_coord, Orientation orientation);

    void place_ship(int coord_x, int coord_y, Ship* ship);

    void attack_cell(int coord_x, int coord_y);

    void print();

};

