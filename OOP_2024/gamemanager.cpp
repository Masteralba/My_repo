#include "gamemanager.hpp"
#include "parser.hpp"
#include "myexception.hpp"
#include "input.hpp"

GameManager::GameManager()
{
    this->game = new Game();
    this->parser = new Parser();
    this->input = new Input();
    this->game_started = false;

}

void GameManager::load_from_file()
{
    //Ввод

    try{
            this->game->load_from_file();
            this->game_started = true;
    }
    catch(std::runtime_error& e){std::cerr << e.what();}
    catch(FileWasChanged& e){std::cerr << e.what();}
}

void GameManager::load_from_input()
{
    //Ввод и т.д
    try{

    std::vector<int> width_and_height = this->input->get_width_and_height();
    int ships_number = this->input->get_ships_number();
    std::vector<int> player_ships_lenghts = this->input->get_ships_lenghts(ships_number);

    std::vector<Orientation> player_ships_orientations = this->input->get_ships_orientations(ships_number);

    std::vector<std::vector<int>> player_ships_coordinates = this->input->get_coordinates(ships_number);

    this->game->load_from_input(width_and_height[0], width_and_height[1], ships_number, // Загрузиться из ввода
    player_ships_lenghts,
    player_ships_orientations,
    player_ships_coordinates);
    }
    catch (ImproperCooordsInput& e) {std::cerr << e.what();}
    catch (ImproperLenghtsInput& e) {std::cerr << e.what();}
    catch (ImproperOrieantationsInput& e) {std::cerr << e.what();}
    catch (ImproperShipsNumberInput& e) {std::cerr << e.what();}
    catch( ImproperWidthAndHeightInput& e) {std::cerr << e.what();}
}

void GameManager::save_to_file()
{
    //Ввод имени файла
    this->game->save_to_file();
}

void GameManager::attack()
{
    try
    {
        std::vector<int> coords = this->input->get_attack_coords();
        this->game->player_attack(coords[0], coords[1]);
    }
    catch ( ImproperCooordsInput& e ) {std::cerr << e.what();}
}

void GameManager::use_ability()
{
    if (this->game_started) this->game->use_ability();
}

void GameManager::use_command()
{
    try{
        Commands command = this->parser->get_command();
        switch (command)
        {
        case Commands::ATTACK :
        {
            this->attack();
            break; 
        }
        case Commands::LOAD_FROM_FILE:
        {
            this->load_from_file();
            break;
        }

        case Commands::LOAD_FROM_INPUT:
        {
            this->load_from_input();
            break;
        }

        case Commands::USE_ABILITY:
        {
            this->use_ability();
            break;
        }

        default:
            break;
        }

    } catch (ImproperCommandInput& e) {std::cerr << e.what();}
}