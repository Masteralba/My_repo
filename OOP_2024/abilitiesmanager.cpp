#include <iostream>
#include "abilitiesmanager.hpp"

Abilitiesmanager::Abilitiesmanager()
{
    std::vector<Iability*> temp_vector = {new Scanner, new Double_damage, new Shelling};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(temp_vector.begin(), temp_vector.end(), gen);
    abilities.push(temp_vector[0]);
    abilities.push(temp_vector[1]);
    abilities.push(temp_vector[2]);
}

void Abilitiesmanager::use_ability(Field* field)
{
    Iability* ability = this->abilities.front();
    this->abilities.pop();
    ability->use_skill(field);
}

void Abilitiesmanager::add_ability()
{
    std::vector<Iability*> temp_vector = {new Scanner, new Double_damage, new Shelling};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(temp_vector.begin(), temp_vector.end(), gen);
    abilities.push(temp_vector[0]);
}