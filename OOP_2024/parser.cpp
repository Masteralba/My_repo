#include "parser.hpp"
#include "myexception.hpp"
#include <iostream>

Commands Parser::get_command()
{
    this->command = getchar();
    switch (command)
    {
    case 'a':
        return Commands::ATTACK;
        break;
    case 'b':
        return Commands::LOAD_FROM_FILE;
        break;
    case 's':
        return Commands::SAVE;
        break;
    case 'l':
        return Commands::LOAD_FROM_INPUT;
        break;
    case 'u':
        return Commands::USE_ABILITY;
        break;
    case 'd':
        return Commands::STOP;
        break;
    default:
        throw ImproperCommandInput(command);
        break;
    }
}