#include <iostream>
#include <fstream>
#include "fileprocessor.hpp"

void FileProcessor::save_gamestate(GameState* gamestate, const char* filename)
{
    //file prcessing
    std::ofstream out(filename);
    if (out.is_open())
    {
        out << *gamestate << std::endl;
    }
    out.close();
}

void FileProcessor::load_gamestate(GameState* gamestate, const char* filename)
{
    std::ifstream in(filename); // окрываем файл для чтения
    if (in.is_open())
    {
        in >> *gamestate;
    }

    in.close();
}