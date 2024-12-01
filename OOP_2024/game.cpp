#include <iostream>
#include <random>
#include <algorithm>
#include "game.hpp"


void Game::attack_enemy_field(int x_coord, int y_coord)
{
    int destroyed_number_before = this->enemy_shipmanager->destroyed_number();
    try{
        this->enemy_field->attack_cell(x_coord, y_coord, this->flags->double_damage);
        if (this->flags->double_damage) this->flags->double_damage=false;;
    }catch(AttackOutOfBounds& e)
    {
        std::cout << e.what();
        return;
    }
    int destroyed_nuber_after = this->enemy_shipmanager->destroyed_number();
    if ( destroyed_nuber_after > destroyed_number_before) this->abilitiesmanager->add_ability();
}

void Game::attack_player_field()
{
    srand((unsigned)time(0)); 
    int coord_x, coord_y;
    coord_x = (rand()%this->field->get_width());
    coord_y = (rand()%this->field->get_height());
    std::cout << "Random attack: "<< coord_x << " " << coord_y << std::endl;
    try
    {
        this->field->attack_cell(coord_x, coord_y, false);
    }catch(AttackOutOfBounds& e){}
}

void Game::use_ability()
{
    int destroyed_number_before = this->shipmanager->destroyed_number();
    try{
        this->abilitiesmanager->use_ability(this->enemy_field, this->flags);
    }catch(AbilityUseInEmptyManger& e)
    {
        std::cout << e.what();
        return;
    }
    int destroyed_nuber_after = this->shipmanager->destroyed_number();
    if ( destroyed_nuber_after > destroyed_number_before) this->abilitiesmanager->add_ability();
}

void Game::player_start(std::vector<std::vector<int>> coordinates_vector)
{
    for (size_t lenght_iterator=0; lenght_iterator<coordinates_vector.size(); lenght_iterator++)
    {
        try{
            this->field->place_ship(coordinates_vector[lenght_iterator][0], coordinates_vector[lenght_iterator][1],
            this->shipmanager->get_ship(lenght_iterator));
        }catch(ShipIntersection& e)
        {
            std::cout << e.what();
        }catch(IncorrectShipPlace& e)
        {
            std::cout<< e.what();
        }
    }
}

void Game::enemy_start(std::vector<std::vector<int>> coordinates_vector)
{
    for (size_t lenght_iterator=0; lenght_iterator<coordinates_vector.size(); lenght_iterator++)
    {
        try
        {
            this->enemy_field->place_ship(coordinates_vector[lenght_iterator][0], coordinates_vector[lenght_iterator][1],
            this->enemy_shipmanager->get_ship(lenght_iterator));
        }
        catch
            (ShipIntersection& e){std::cout << e.what();}
        catch
            (IncorrectShipPlace& e){std::cout<< e.what();}
    }
}

void Game::round()
{
    std::cout << "Do you want to use an ability: [y] or [n]:" << std::endl;
    char ability;
    std::cin >> ability;
    if (ability == 'y') this->use_ability();
    std::cout << "Input attack coords" << std::endl;
    int coord_x, coord_y;
    std::cin >> coord_x >> coord_y;
    this->attack_enemy_field(coord_x, coord_y);

    this->attack_player_field();
}

void Game::main(int width, int height, int number_of_ships, std::vector<int> lenghts,
    std::vector<Orientation> orientations, std::vector<std::vector<int>> coorditanes)
{
    int counter = 1;
    while(!this->shipmanager->all_ships_destroyed() && !this->enemy_shipmanager->all_ships_destroyed())
    {
        std::cout << "Round number: " << counter++ << std::endl;
        this->round();
        this->field->print();
        printf("%c", '\n');
        this->enemy_field->print();
    }

    if (this->enemy_shipmanager->all_ships_destroyed())
    {
        std::cout << "You Won! New game starts:\n";
        this->enemy_shipmanager = new ShipManager(number_of_ships, lenghts, orientations);
        this->enemy_field = new Field(width, height);
        this->enemy_start(coorditanes);
        this->main(width, height, number_of_ships, lenghts, orientations, coorditanes);
    }
    else
    {
        std::cout << "You Lost! New game starts:\n";
        this->field = new Field(width, height);
        this->shipmanager = new ShipManager(number_of_ships, lenghts, orientations);
        this->player_start(coorditanes);
        this->main(width, height, number_of_ships, lenghts, orientations, coorditanes);
    }
}