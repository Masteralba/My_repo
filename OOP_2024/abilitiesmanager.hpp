#pragma once
#include <random>
#include <algorithm>
#include <queue>
#include "abilities.hpp"
#include "field.hpp"

class Abilitiesmanager
{
    private:
    
    std::queue<Iability*> abilities;

    public:

    Abilitiesmanager();

    void use_ability(Field* field);

    void add_ability();

};