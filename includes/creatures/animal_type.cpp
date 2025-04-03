

#include "../creatures/animal_type.h"

    Wall::Wall(int i, int j) : Creature(i,j){


    }
    void Wall::print(){
        cout << "Z";
    }





    Prey::Prey(int i, int j) : Creature(i,j), _count(0){

    }
    
    void Prey::breed(Creature* grid[20][20]){
        //cout << "_count: " << _count << endl;

        if (_count == 3){
            int a = randomNum();
            Loc* ptr = find_blank(grid);
            if (ptr->i == 0){
                return;
            }
            while ((ptr + a) -> i == 0){
                a = randomNum();
            }
            grid[(ptr+a)->i][(ptr+a)->j] = new Prey((ptr+a)->i,(ptr+a)->j);
            _count = 0;
        }

        _count++;
        
    }
   
   void Prey::move(Creature* grid[20][20]){
        int a = randomNum();
        Loc* ptr = find_blank(grid);
        if (ptr->i == 0){
            return;
        }
        while ((ptr + a) -> i == 0){
            a = randomNum();
        }

    
        move_to(grid, *(ptr+a));

    }

   
    
    void Prey::print(){
        cout << "O";
    }


    Predator::Predator(int i, int j) : Creature(i,j), _count(0){

    }
    


    void Predator::breed(Creature* grid[20][20]){
        
         if (_count == 11){
            int a = randomNum();
            Loc* ptr = find_blank(grid);
            if (ptr->i == 0){
                return;
            }
            while ((ptr + a) -> i == 0){
                a = randomNum();
            }
            grid[(ptr+a)->i][(ptr+a)->j] = new Predator((ptr+a)->i,(ptr+a)->j);
            _count = 0;
        }

        _count++;
        

    }


     void Predator::move(Creature* grid[20][20]){

        int a = randomNum();
        Loc* ptr = find_creature(grid);
        if (ptr->i == 0){
            ptr = find_blank(grid);
            if (ptr->i == 0){
                return;
            }
            while((ptr + a) -> i == 0){
                a = randomNum();
            }
            if (get_moved() == false){ 
                _starve_count++;

            }
            move_to(grid, *(ptr+a));

            if(_starve_count == 9){
                kill(grid);
            }
            return;


        }
        while ((ptr + a) -> i == 0){
            a = randomNum();
        }

        grid[(ptr+a)->i][(ptr+a)->j]->kill(grid); 
        move_to(grid, *(ptr+a));


    }
    
    void Predator::print(){
        cout << "X";
    }