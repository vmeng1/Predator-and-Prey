


#ifndef ANIMAL_TYPE_H
#define ANIMAL_TYPE_H

#include "../creatures/creature.h"


class Wall:public Creature
{
    public:
        Wall(int i, int j);
        void print();
    private:
        


};

class Prey: public Creature
{
    public:
        Prey(int i, int j);
        int get_type(){return 1;}
        void breed(Creature* grid[20][20]);
        void move(Creature* grid[20][20]);

        void print();
    private:
        int _count;
        int _type;

};

class Predator: public Creature
{
    public: 
        Predator(int i, int j);
        int get_type(){return 2;}
        void breed(Creature* grid[20][20]);
        void move(Creature* grid[20][20]);
        
        void print();
        
    private:
        int _count;
        int _type;
        int _starve_count;
};

#endif

