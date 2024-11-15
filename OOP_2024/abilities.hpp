#pragma once
#include <iostream>
#include "field.hpp"
#include <string>

#define SCANNER_X_SIZE 2
#define SCANNER_Y_SIZE 2

class Iability
{
public:
    virtual void use_skill(Field* field) = 0;
    virtual std::string as_string() = 0;
};

class Double_damage: public Iability
{
    public:

    void use_skill(Field* field) {field->set_double_attack();}

    std::string as_string(){return "Double damage ability";}

};

class Scanner: public Iability
{
    public:

    void use_skill(Field* field);

    std::string as_string(){return "Scanner ability";}

};

class Shelling: public Iability
{
    public:

    void use_skill(Field* field);

    std::string as_string(){return "Shelling ability";}
};




