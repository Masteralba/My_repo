#pragma once
#include "game.hpp"
#include "parser.hpp"
#include "input.hpp"


class GameManager
{
    public:

    bool game_started;

    GameManager();

    void use_command();

    void start();

    void main();

    Game* game;

    Parser* parser;

    Input* input;

    private:

    void load_from_file();

    void load_from_input();

    void save_to_file();

    void attack();

    void use_ability();

};