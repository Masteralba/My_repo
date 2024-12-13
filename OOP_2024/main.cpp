#include <iostream>
#include "gamemanager.hpp"

int main()
{
    GameManager* gamemanager = new GameManager();
    // загрузка из ввода или из файла
    while(1)
    {
        gamemanager->use_command();
    }
    return 0;
}