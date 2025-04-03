#ifndef GRID_H
#define GRID_H

#include "../creatures/creature.h"
#include "../creatures/animal_type.h"

class Grid{
    public:
        Grid(); //init the grid 10 x 10, set everything to nullptr
        void fillGrid(); //populates the grid with certain amount of prey and predators
        void step(); //double for loop, call the move function for each creature
        bool all_alive();
        bool any_alive(); //returns true if creature count > 0
        friend ostream& operator <<(ostream& outs, Grid g);
        
    private:
         Creature *_grid[20][20];
       
};

#endif