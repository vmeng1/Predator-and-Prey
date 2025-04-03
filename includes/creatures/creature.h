#ifndef CREATURE_H
#define CREATURE_H

#include "../../includes/Random/random.h"
#include "../creatures/loc.h"

using namespace std;


class Creature{
    public:
        Creature (int row, int col);
        Creature(Loc &loc);

        void move_to(Creature* world[20][20],Loc &loc);
        void moved_false(){_moved = false;}
        bool get_moved(){return _moved;}
        void kill(Creature* grid[20][20]);
        Loc* find_blank(Creature* grid[20][20]);
        Loc* find_creature(Creature* grid[20][20]);

        virtual int get_type(){return 0;}
        virtual void move(Creature* grid[20][20]);
        virtual void breed(Creature* grid[20][20]);
        virtual void print();
        
    private:
        Loc _loc;
        bool _moved;

};

#endif