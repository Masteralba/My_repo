#include <iostream>
#include <random>
#include <algorithm>
#include "game.hpp"
#include "fileprocessor.hpp"


void Game::attack_enemy_field(int x_coord, int y_coord)
{
    int destroyed_number_before = this->get_gamestate()->enemy_shipmanager->destroyed_number();
    try{
        this->get_gamestate()->enemy_field->attack_cell(x_coord, y_coord, this->get_gamestate()->flags->double_damage);
        if (this->get_gamestate()->flags->double_damage) this->get_gamestate()->flags->double_damage=false;;
    }catch(AttackOutOfBounds& e)
    {
        std::cout << e.what();
        return;
    }
    int destroyed_nuber_after = this->get_gamestate()->enemy_shipmanager->destroyed_number();
    if ( destroyed_nuber_after > destroyed_number_before) this->get_gamestate()->abilitiesmanager->add_ability();
}

void Game::attack_player_field()
{
    srand((unsigned)time(0)); 
    int coord_x, coord_y;
    coord_x = (rand()%this->get_gamestate()->player_field->get_width());
    coord_y = (rand()%this->get_gamestate()->player_field->get_height());
    try
    {
        this->get_gamestate()->player_field->attack_cell(coord_x, coord_y, false);
    }catch(AttackOutOfBounds& e){}
}

void Game::use_ability()
{
    int destroyed_number_before = this->get_gamestate()->enemy_shipmanager->destroyed_number();
    try{
        this->get_gamestate()->abilitiesmanager->use_ability(this->get_gamestate()->enemy_field, this->get_gamestate()->flags);
    }catch(AbilityUseInEmptyManger& e)
    {
        std::cout << e.what();
        return;
    }
    int destroyed_nuber_after = this->get_gamestate()->enemy_shipmanager->destroyed_number();
    if ( destroyed_nuber_after > destroyed_number_before) this->get_gamestate()->abilitiesmanager->add_ability();
}

void Game::player_start()
{
    for (size_t lenght_iterator=0; lenght_iterator<this->get_gamestate()->player_ships_coordinates.size(); lenght_iterator++)
    {
        try{
            this->get_gamestate()->player_field->place_ship(
                this->get_gamestate()->player_ships_coordinates[lenght_iterator][0], 
                this->get_gamestate()->player_ships_coordinates[lenght_iterator][1],
            this->get_gamestate()->player_shipmanager->get_ship(lenght_iterator));
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
    for (size_t lenght_iterator=0; lenght_iterator<this->get_gamestate()->enemy_ships_coordinates.size(); lenght_iterator++)
    {
        try{
            this->get_gamestate()->enemy_field->place_ship(
                this->get_gamestate()->enemy_ships_coordinates[lenght_iterator][0], 
                this->get_gamestate()->enemy_ships_coordinates[lenght_iterator][1],
            this->get_gamestate()->enemy_shipmanager->get_ship(lenght_iterator));
        }catch(ShipIntersection& e){}
        catch(IncorrectShipPlace& e){}
    }
}

void Game::player_tern(int coord_x, int coord_y, bool ability_flag)
{
    this->attack_enemy_field(coord_x, coord_y);
    if (ability_flag){
        this->use_ability();
        ability_flag = false;
    }
}

void Game::enemy_tern(){this->attack_player_field();}

void Game::round(int coord_x, int coord_y, bool ability_flag)
{
    this->player_tern(coord_x, coord_y, ability_flag);
    this->enemy_tern();
}

void Game::check_win()
{
    if (this->get_gamestate()->enemy_shipmanager->all_ships_destroyed()) // Проиграл противник
    {
        this->get_gamestate()->enemy_field = new Field(this->get_gamestate()->enemy_field->get_width(), this->get_gamestate()->enemy_field->get_height() );
        this->get_gamestate()->enemy_shipmanager = new ShipManager(this->get_gamestate()->enemy_shipmanager->get_ships_number(), this->get_gamestate()->enemy_shipmanager->get_ships_lenghts(),
        this->get_gamestate()->enemy_shipmanager->get_ships_orientations());
        this->enemy_start();
    }
    else  // проиграл игрок
    {
        this->get_gamestate()->player_field = new Field(this->get_gamestate()->player_field->get_width(), this->get_gamestate()->player_field->get_height() );
        this->get_gamestate()->player_shipmanager = new ShipManager(this->get_gamestate()->player_shipmanager->get_ships_number(), this->get_gamestate()->player_shipmanager->get_ships_lenghts(),
        this->get_gamestate()->player_shipmanager->get_ships_orientations());
        this->get_gamestate()->abilitiesmanager = new AbilitiesManager();
        this->get_gamestate()->flags = new Flags();
        this->player_start();
    }
}


void Game::save(const char* filename)
{
    try{
    FileProcessor* fileprocessor = new FileProcessor(std::ios::out, filename);
    fileprocessor->save_gamestate(this->get_gamestate());
    } catch (std::runtime_error e)
    {
        std::cout << e.what() << std::endl;
        return;
    }   
}

void Game::load(const char* filename)
{   
    try{
    FileProcessor* fileprocessor = new FileProcessor(std::ios::in, filename);
    fileprocessor->save_gamestate(this->get_gamestate());
    } catch (std::runtime_error e)
    {
        std::cout << e.what() << std::endl;
        return;
    } catch (FileWasChanged& e)
    {
        std::cout << e.what() << std::endl;
        return;
    }
}