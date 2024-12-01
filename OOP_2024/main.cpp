#include <iostream>
#include <vector>
#include "game.hpp"

int main()
{
    int width = 10;
    int height = 10;
    int number_of_ships=1;
    std::vector<int> lenghts = {4};
    std::vector<Orientation> orientations = {Orientation::horisontal, Orientation::horisontal, Orientation::horisontal, 
    Orientation::vertical, Orientation::vertical };
    Field* field = new Field(width, height);
    ShipManager* shipmanager = new ShipManager(number_of_ships, lenghts, orientations);
    Field* enemy_field = new Field(width, height);
    ShipManager* enemy_shipmanager = new ShipManager(number_of_ships, lenghts, orientations);
    std::vector<std::vector<int>> coorditanes = {{0, 0}};
    Game* game = new Game(field, shipmanager, enemy_field, enemy_shipmanager, new AbilitiesManager(), new Flags());
    game->player_start(coorditanes);
    game->enemy_start(coorditanes);
    game->field->print();
    printf("%c", '\n');
    game->enemy_field->print();
    game->main(width, height, number_of_ships, lenghts, orientations, coorditanes);
    return 0;
}