#pragma once
#include <iostream>
#include <vector>
#include "gamestate.hpp"

enum class Commands
{
    ATTACK='a',
    USE_ABILITY='u',
    SAVE='s',
    LOAD_FROM_FILE='l',
    LOAD_FROM_INPUT='i',
    HELP='h',
    STOP = 'd'
};

class Parser
{
    public:

    Parser(){};

    Commands get_command();

    private:

    char command;
};