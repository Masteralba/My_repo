#pragma once
#include <random>
#include <algorithm>
#include <vector>
#include "abilities.hpp"
#include "field.hpp"
#include "flags.hpp"

class AbilitiesManager
{
    private:

    Flags* flags;
    
    std::vector<Iability*> abilities;

    public:

    AbilitiesManager();

    bool get_flag(){return this->flags->double_damage;}

    void change_flag(){this->flags->double_damage = !this->flags->double_damage;}

    void use_ability(Field* field);

    void add_ability();

    void print_abilityes();

};