#include <iostream>
#include <vector>
#include "ship.hpp"
#include "field.hpp"


void Field::Cell::set_status(CellStatus status, Ship* ship, int ind)
{
    switch (status)
    {
    case CellStatus::empty:
        this->cellstatus = CellStatus::empty;
        break;
    case CellStatus::ship:
        this->cellstatus = CellStatus::ship;
        this->set_ship(ship);
        this->set_ind(ind);
        break;
    default:
        std::cerr << "Default in Cell->set_status" << std::endl;
        break;
    }
}

void Field::Cell::set_ship(Ship* ship) {this->ship = ship;}

void Field::Cell::set_ind(int ind) {this->ind = ind;}

CellStatus Field::Cell::get_status() {return this->cellstatus;}

Ship* Field::Cell::get_ship() {return this->ship;}

int Field::Cell::get_ind() {return this->ind;}

Field::Field(int width, int height):width(width),height(height)
{
        for(size_t y_coord=0; y_coord < this->height; y_coord++)
        {
            std::vector<Cell*> cell_array;
            for(size_t x_coord=0;x_coord<this->width; x_coord++) cell_array.push_back(new Cell(y_coord,x_coord));
            this->cells.push_back(cell_array);
        }
}

Field::~Field()
{
    for(size_t y_coord=0; y_coord < this->height; y_coord++)
        for(size_t x_coord=0; x_coord< this->width; x_coord++)
            delete this->cells[y_coord][x_coord];
}

Field::Field(const Field& field):width(field.width),height(field.height)
{
    for(size_t y_coord=0; y_coord<this->height; y_coord++)
    {
        std::vector<Cell*> cell_array;
        for(size_t x_coord=0; x_coord<this->width; x_coord++) cell_array.push_back(new Cell(y_coord, x_coord));
        this->cells.push_back(cell_array);
    }
    for(size_t y_coord=0; y_coord<this->height; y_coord++)
    {
        for(size_t x_coord=0; x_coord<this->width; x_coord++)
        {
            if ( field.cells[y_coord][x_coord]->get_ship() != nullptr)
            {
                Ship* new_ship = new Ship(*field.cells[y_coord][x_coord]->get_ship());
                {
                    for(size_t temp_y_coord=0; temp_y_coord<this->height; temp_y_coord++)
                    {
                        for(size_t temp_x_coord=0; temp_x_coord<this->width; temp_x_coord++)
                        {
                            if ( field.cells[y_coord][x_coord]->get_ship() == field.cells[temp_y_coord][temp_x_coord]->get_ship() )
                            {
                                int temp_ind = field.cells[temp_y_coord][temp_x_coord]->get_ind();
                                this->cells[temp_y_coord][temp_x_coord]->set_status(CellStatus::ship, new_ship, temp_ind);
                            }
                        }
                    }
                }
            }
        }
    }
}

Field& Field::operator = (const Field& field)
{
    Field temp_field(field);
    std::swap(this->height, temp_field.height);
    std::swap(this->width, temp_field.width);
    std::swap(this->cells, temp_field.cells);
    return *this;
}

Field::Field(Field&& field):width(0),height(0),cells(0){std::swap(this->cells, field.cells);}

Field& Field::operator = (Field&& field){
    if (this != & field)
    {
        std::swap(this->height, field.height);
        std::swap(this->width, field.width);
        std::swap(this->cells, field.cells);
    }
    return *this;
}

CellStatus Field::get_cell_status(int coord_x, int coord_y)
{
    if ( coord_x < this->width && coord_x >= 0 && coord_y < this->height && coord_y >= 0)
        return this->cells[height-1-coord_y][coord_x]->get_status();
    else 
        return CellStatus::outofbound;
}

void Field::set_cell(int coord_x, int coord_y, CellStatus status, Ship* ship, int ind)
{
    (this->cells[height-1-coord_y][coord_x])->set_status(status, ship, ind);
}

bool Field::check_ship_intersection(int coord_x, int coord_y, int temp_coord, Orientation orientation)
{
    if ( temp_coord == 0)
    {
        return ( (this->get_cell_status(coord_x-1, coord_y) == CellStatus::ship) // check for
        || (this->get_cell_status(coord_x+1, coord_y) == CellStatus::ship)       //  *  0  *
        ||  (this->get_cell_status(coord_x, coord_y-1) == CellStatus::ship)      //  0  0  0
        || (this->get_cell_status(coord_x, coord_y+1) == CellStatus::ship)       //  *  0  *
        || (this->get_cell_status(coord_x, coord_y) == CellStatus::ship));       
    }
    else
        switch (orientation)
        {
        case Orientation::horisontal :
            return ( (this->get_cell_status(temp_coord+1, coord_y) == CellStatus::ship) //  *  0  *
            || (this->get_cell_status(temp_coord, coord_y+1) == CellStatus::ship)       //  *  0  0
            ||  (this->get_cell_status(temp_coord, coord_y-1) == CellStatus::ship));    //  *  0  * 
            break;
        case Orientation::vertical :
            return ( (this->get_cell_status(coord_x+1, temp_coord) == CellStatus::ship) //  *  0  *
            || (this->get_cell_status(coord_x-1, temp_coord) == CellStatus::ship)       //  0  0  0
            ||  (this->get_cell_status(coord_x, temp_coord+1) == CellStatus::ship));    //  *  *  * 
        default:
            std::cout << "Defalut in Ship::check_ship_intersection" << std::endl;
            return false;
            break;
        }
}

void Field::place_ship(int coord_x, int coord_y, Ship* ship)
{
    if ( coord_x<0 || coord_y<0 || coord_x >= this->width || coord_y >= this->height) return;
    int index_counter = 0;
    switch (ship->get_orientation())
    {
    case Orientation::horisontal :
        for(size_t temp_coord=coord_x; temp_coord < coord_x + ship->get_lenght(); temp_coord++)
        {
            if (!this->check_ship_intersection(coord_x, coord_y, temp_coord, Orientation::horisontal))
            {
                this->set_cell(temp_coord, coord_y, CellStatus::ship, ship, index_counter++);
            }
        }
        break;
    case Orientation::vertical :
        for(size_t temp_coord=coord_y; temp_coord < coord_y + ship->get_lenght(); temp_coord++)
        {
            if (!this->check_ship_intersection(coord_x, coord_y, temp_coord, Orientation::vertical))
            {
                this->set_cell(coord_x, temp_coord, CellStatus::ship, ship, index_counter++);
            }
        }
        break;
    default:
        std::cout << "Default in Field::place_ship";
        break;
    }
}

void Field::attack_cell(int coord_x, int coord_y)
{
    if ( coord_x<0 || coord_y<0 || coord_x >= this->width || coord_y >= this->height) return;
    switch (this->cells[height-1-coord_y][coord_x]->get_status())
    {
    case CellStatus::ship:
    {
        int attack_index = this->cells[height-1-coord_y][coord_x]->get_ind();
        this->cells[height-1-coord_y][coord_x]->get_ship()->attack_segment(attack_index);
        break;
    }
    case CellStatus::empty:
        std::cout << "The empty cell was attacked" << std::endl;
        break;
    case CellStatus::unknown:
        break;
    default:
        std::cout << "Defult in Field::attack_cell" << std::endl;
        break;
    }
}

void Field::print()
{
    for(size_t coord_x=0; coord_x<this->height; coord_x++)
    {
        for(size_t coord_y=0; coord_y<this->width; coord_y++)
        {
            if (this->cells[coord_x][coord_y]->get_status() == CellStatus::ship)
                this->cells[coord_x][coord_y]->get_ship()->print_segment(this->cells[coord_x][coord_y]->get_ind());
            else
                std::cout << static_cast<char>(this->cells[coord_x][coord_y]->get_status()) << " ";
        }
        std::cout << std::endl;
    }
}


