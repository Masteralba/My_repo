#include <iostream>
#include <vector>

#define MAX_SHIP_LENGHT 4
#define MIN_SHIP_LENGHT 1

enum class Condition { undamaged, damaged, destroyed};
enum class Orientation { vertical, horisontal};

class Ship{
private:


    class Segment
    {
    private:
        Condition condition;
    public:

        Segment(){ this->condition = Condition::undamaged;}
        void attack(){
            switch (this->condition)
            {
            case Condition::undamaged:
                this->condition = Condition::damaged;
                break;
            case Condition::damaged:
                this->condition = Condition::destroyed;
                break;
            case Condition::destroyed:
                std::cout << "The Segment is already destroyed" << std::endl;
                break;
            default:
                std::cout << "Defualt in Ship::Segment::attack" << std::endl;
                break;
            }
        }


        Condition get_condition()
        {
            return this->condition;
        }


    };

    int lenght;
    Orientation orientation;
    std::vector<Segment*> segments; 

public:


    Ship(int lenght, Orientation orientation):lenght(lenght)
    {
        
        if (this->lenght > MAX_SHIP_LENGHT || this->lenght < MIN_SHIP_LENGHT)
        {
            std::cerr << "Incorrect ship lenght" << std::endl;
            exit(1);
        } 

        switch (orientation)
        {
        case Orientation::vertical:
            this->orientation = Orientation::vertical;
            break;
        case Orientation::horisontal:
            this->orientation = Orientation::horisontal;
            break;
        default:
            std::cout << "Deffalut in Ship::Constructor" << std::endl;
            break;
        }
        for(size_t segment_iterator=0; segment_iterator<this->lenght; segment_iterator++) segments.push_back(new Segment());
    }

    Ship(const Ship& ship):lenght(ship.lenght),orientation(ship.orientation)
    {
        for(size_t segment_iterator=0; segment_iterator<this->lenght; segment_iterator++)
        {
            Segment* segment_copy = new Segment(*ship.segments[segment_iterator]);
            this->segments.push_back(segment_copy);
        }
    }

    Ship& operator = (const Ship& ship)
    {
        Ship temp_ship(ship);
        std::swap(this->lenght, temp_ship.lenght);
        std::swap(this->orientation, temp_ship.orientation);
        std::swap(this->segments, temp_ship.segments);
        return *this;
    }

    ~Ship() {for(size_t segment_iterator=0; segment_iterator<this->lenght; segment_iterator++) delete segments[segment_iterator];}

    Orientation get_orientation()
    {
        return this->orientation;
    }

    int get_lenght()
    {
        return this->lenght;
    }

    void attack_segment(int ind)
    {
        if ( ind >= MAX_SHIP_LENGHT || ind < MIN_SHIP_LENGHT-1)
        {
             std::cerr << "Incorrect attacking index" << std::endl;
            exit(1);
        } 
        this->segments[ind]->attack();
    }

    void print_segment(int ind)
    {
        if ( ind >= MAX_SHIP_LENGHT || ind < MIN_SHIP_LENGHT-1)
        {
             std::cerr << "Incorrect printing index" << std::endl;
            exit(1);
        } 
        std::cout << static_cast<int>(this->segments[ind]->get_condition())<< " ";
    }

    void print_segments()
    {
        for( size_t lenght_iterator=0; lenght_iterator<lenght; lenght_iterator++)
        {
            std::cout<< static_cast<int>(this->segments[lenght_iterator]->get_condition()) << " ";
        }
        std::cout << std::endl;
    }


};