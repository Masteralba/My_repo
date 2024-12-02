#include <iostream>
#include <random>
#include <algorithm>
#include "game.hpp"

/*
void Game::attack_enemy_field(int x_coord, int y_coord)
{
    int destroyed_number_before = this->gamestate->enemy_shipmanager->destroyed_number();
    try{
        this->gamestate->enemy_field->attack_cell(x_coord, y_coord, this->gamestate->flags->double_damage);
        if (this->gamestate->flags->double_damage) this->gamestate->flags->double_damage=false;;
    }catch(AttackOutOfBounds& e)
    {
        std::cout << e.what();
        return;
    }
    int destroyed_nuber_after = this->gamestate->enemy_shipmanager->destroyed_number();
    if ( destroyed_nuber_after > destroyed_number_before) this->gamestate->abilitiesmanager->add_ability();
}

void Game::attack_player_field()
{
    srand((unsigned)time(0)); 
    int coord_x, coord_y;
    coord_x = (rand()%this->gamestate->player_field->get_width());
    coord_y = (rand()%this->gamestate->player_field->get_height());
    try
    {
        this->gamestate->player_field->attack_cell(coord_x, coord_y, false);
    }catch(AttackOutOfBounds& e){}
}

void Game::use_ability()
{
    int destroyed_number_before = this->gamestate->enemy_shipmanager->destroyed_number();
    try{
        this->gamestate->abilitiesmanager->use_ability(this->gamestate->enemy_field, this->gamestate->flags);
    }catch(AbilityUseInEmptyManger& e)
    {
        std::cout << e.what();
        return;
    }
    int destroyed_nuber_after = this->gamestate->enemy_shipmanager->destroyed_number();
    if ( destroyed_nuber_after > destroyed_number_before) this->gamestate->abilitiesmanager->add_ability();
}

void Game::player_start()
{
    for (size_t lenght_iterator=0; lenght_iterator<this->gamestate->player_ships_coordiantes.size(); lenght_iterator++)
    {
        try{
            this->gamestate->player_field->place_ship(
                this->gamestate->player_ships_coordiantes[lenght_iterator][0], 
                this->gamestate->player_ships_coordiantes[lenght_iterator][1],
            this->gamestate->player_shipmanager->get_ship(lenght_iterator));
        }catch(ShipIntersection& e)
        {
            std::cout << e.what();
        }catch(IncorrectShipPlace& e)
        {
            std::cout<< e.what();
        }
    }
}

void Game::enemy_start()
{
    for (size_t lenght_iterator=0; lenght_iterator<this->gamestate->enemy_ships_coordiantes.size(); lenght_iterator++)
    {
        try{
            this->gamestate->enemy_field->place_ship(
                this->gamestate->enemy_ships_coordiantes[lenght_iterator][0], 
                this->gamestate->enemy_ships_coordiantes[lenght_iterator][1],
            this->gamestate->enemy_shipmanager->get_ship(lenght_iterator));
        }catch(ShipIntersection& e){}
        catch(IncorrectShipPlace& e){}
    }
}

void Game::player_tern(int coord_x, int coord_y, bool ability_flag=false)
{
    this->use_ability();
    if (ability_flag){
        this->attack_enemy_field(coord_x, coord_y); 
        ability_flag = false;
    }
}

void Game::enemy_tern(){this->attack_player_field();}

void Game::round(int coord_x, int coord_y, bool ability_flag=false)
{
    this->player_tern(coord_x, coord_y, ability_flag);
    this->enemy_tern();
}

void Game::main()
{
    while(!this->gamestate->player_shipmanager->all_ships_destroyed() && 
    !this->gamestate->enemy_shipmanager->all_ships_destroyed())
    {
        // вызов высшей сущности, получение координат для атаки, и способностей
        int coord_x, coord_y, ability_flag;
        std::cin >> coord_x >> coord_y >> ability_flag;
        this->round(coord_x, coord_y, ability_flag);
    }

    if (this->gamestate->enemy_shipmanager->all_ships_destroyed())
    {
        //enemy_start
    }
    else
    {
        //player_start
    }
}
*/