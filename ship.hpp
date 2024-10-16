#pragma once
#include <iostream>
#include <vector>

#define MAX_SHIP_LENGHT 4
#define MIN_SHIP_LENGHT 1

enum class Condition { undamaged, damaged, destroyed};
enum class Orientation { vertical, horisontal};

class Ship{
private:

    class Segment{
    private:
        Condition condition;
    public:

        Segment();

        void attack();

        Condition get_condition();

    };

    int lenght;
    Orientation orientation;
    std::vector<Segment*> segments; 

public:

    Ship(int lenght, Orientation orientation);

    Ship(const Ship& ship);

    Ship& operator = (const Ship& ship);

    ~Ship();

    Orientation get_orientation();

    int get_lenght();

    void attack_segment(int ind);

    void print_segment(int ind);

    void print_segments();

};