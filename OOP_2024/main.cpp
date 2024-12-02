#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include "fstream"
#include "gamestate.hpp"

std::ostream& operator << (std::ostream &os, const GameState &gamestate)
{
    std::string data;
    data = std::to_string(gamestate.width) + 
    "|" + std::to_string(gamestate.height)
     + "|" + std::to_string(gamestate.ship_number);
    for (auto elem: gamestate.lenghts) data += "|" + std::to_string(elem);
    for(size_t i=0; i<gamestate.ship_number; i++)
    {
        if (gamestate.orientations[i] == Orientation::horisontal) data += "|h";
        else data += "|v";
    }
    for (auto elem: gamestate.coordinates) data += "|" + std::to_string(elem[0]) + ',' + std::to_string(elem[1]);
    for (auto elem: gamestate.ship_conditions)
    {
        data += "|";
        for (auto condition: elem) data += std::to_string(condition);
    } 
    return os << data;
}

void adv_tokenizer(std::string s, char del)
{
    std::stringstream ss(s);
    std::string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        std::cout << word << std::endl;
    }
}

std::istream& operator >> (std::istream& in, GameState &gamestate)
{
    std::string input_string;
    in >> input_string;
    std::stringstream ss(input_string);
    std::string word;
    int counter = -1;
    while (!ss.eof())
    {
        counter++;
        getline(ss, word, '|');
        if (counter <= 2){
            if (counter == 0) gamestate.width = std::stoi(word);
            if (counter == 1) gamestate.height = std::stoi(word);
            if (counter == 2) gamestate.ship_number = std::stoi(word);
        }
        else{
            if (2 < counter && counter <= 2 + gamestate.ship_number)
            {
                gamestate.lenghts.push_back(std::stoi(word)); 
            }
            if (2 + gamestate.ship_number < counter && counter <= 2 + gamestate.ship_number*2)
            {
                gamestate.orientations.push_back(word == "h" ? 
                Orientation::horisontal : Orientation::vertical); 
            }
            if (2 + gamestate.ship_number*2 < counter && counter <= 2 + gamestate.ship_number*3)
                {}
            if (2 + gamestate.ship_number*3 < counter && counter <= 2 + gamestate.ship_number*4) {}
        }      
    }
    return in;
}

int main()
{
    std::vector<int> lenghts = {1, 2, 3};
    std::vector<Orientation> orientations = {Orientation::horisontal, Orientation::horisontal, Orientation::vertical};
    std::vector<std::vector<int>> coordinates = {{0, 0}, {1, 2}, {5, 6}};
    std::vector<std::vector<int>> ship_conditions = {{0}, {1, 2, 0}, {0, 0, 1}};
    GameState* gamestate = new GameState(10, 12, 3, lenghts, orientations, coordinates, ship_conditions);
    std::ofstream out("data.txt");
    if (out.is_open())
    {
        out << *gamestate << std::endl;
    }
    out.close();

    GameState* newgamestate = new GameState();
 
    std::ifstream in("data.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        in >> *newgamestate;
    }

    in.close();

    std::cout << newgamestate->width << " " << newgamestate->height <<
    " " << newgamestate->ship_number << " " << std::endl;
    for (auto elem: newgamestate->lenghts) std::cout << elem << " ";
    std::cout << std::endl;
    for (auto elem: newgamestate->orientations) std::cout << static_cast<char>(elem) << " ";
    std::cout << std::endl;

    return 0;
}