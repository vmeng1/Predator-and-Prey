
#include "../creatures/creature.h"

Creature::Creature (int row, int col) : _loc(row,col), _moved(false){

}

Creature::Creature(Loc &loc) : _loc(loc), _moved(false){

}

void Creature::kill(Creature* grid[20][20]){
    grid[_loc.i][_loc.j] = nullptr;
    delete this;

}

void Creature::move_to(Creature* world[20][20],Loc &loc){
    
    if (_moved == false){
        //use loc to get ptr;
        world[loc.i][loc.j] = world[_loc.i][_loc.j]; //set creature ptr to new loc
        world[_loc.i][_loc.j] = nullptr; //set og loc to null
        _loc = Loc(loc.i,loc.j); //update creature's i and j
        _moved = true;
    }

}

Loc* Creature::find_blank(Creature* grid[20][20]){
    
    Loc* array_loc = new Loc[8](); 
    int a = 0;

    for (int i = _loc.i - 1; i <= _loc.i + 1; i++){
        for (int j = _loc.j - 1; j <= _loc.j + 1; j++){

            if (grid[i][j] == nullptr){ 
            
                array_loc[a] = Loc(i,j);
                a++;

            }
        }
    
    }


    return array_loc;
          

}
Loc* Creature::find_creature(Creature* grid[20][20]){

    Loc* array_loc = new Loc[8](); 
    int a = 0;

    for (int i = _loc.i - 1; i <= _loc.i + 1; i++){
        for (int j = _loc.j - 1; j <= _loc.j + 1; j++){

            if (grid[i][j] != nullptr && grid[i][j]->get_type() == 1){ 
            
                array_loc[a] = Loc(i,j);
                a++;

            }
        }
    
    }

     return array_loc;


}

                            
void Creature::move(Creature* grid[20][20]){

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
void Creature::breed(Creature* grid[20][20]){
    
    cout << "breed" << endl;
}
void Creature::print(){
    cout << "c";

}
