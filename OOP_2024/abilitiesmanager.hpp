#pragma once
#include <random>
#include <algorithm>
#include <vector>
#include "abilities.hpp"
#include "field.hpp"

class AbilitiesManager
{
    private:

    bool double_attack;
    
    std::vector<Iability*> abilities;

    public:

    AbilitiesManager();

    void use_ability(Field* field);

    void add_ability();

    void print_abilityes();

};