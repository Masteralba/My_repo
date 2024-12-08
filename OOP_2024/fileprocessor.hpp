#pragma once
#include "gamestate.hpp"

class FileProcessor
{
    public:
    
    FileProcessor(){}

    void save_gamestate(GameState* gamestate, const char* filename="save.txt");

    void load_gamestate(GameState* gamestate, const char* filename="save.txt");
};