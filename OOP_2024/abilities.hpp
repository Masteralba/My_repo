#pragma once
#include <iostream>
#include "field.hpp"

#define SCANNER_X_SIZE 2
#define SCANNER_Y_SIZE 2

class Iability
{
public:
    virtual void use_skill(Field* field) = 0;
};

class Double_damage: public Iability
{
    public:

    void use_skill(Field* field) {field->set_double_attack();}

};

class Scanner: public Iability
{
    public:

    void use_skill(Field* field);

};

class Shelling: public Iability
{
    public:

    void use_skill(Field* field);
};




