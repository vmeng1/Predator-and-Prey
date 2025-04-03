
#include "../creatures/grid.h"

Grid::Grid(){
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
            _grid[i][j] = nullptr;
        }
    }
} //init the grid 20 x 20, set everything to nullptr
void Grid::fillGrid(){
    
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
           
            if ((i == 0 || i ==19) || (j==0 || j ==19)){
                _grid[i][j] = new Wall(i,j);
            }
        }
    }

    
    for (int prey = 0; prey <= 26; prey++){
        Loc location = randomLoc();
        while (_grid[location.i][location.j] != nullptr){
            location = randomLoc();
        }
        _grid[location.i][location.j] = new Prey(location.i,location.j);
    }

    for (int predator = 0; predator <= 13; predator++){
        Loc location = randomLoc();
        while (_grid[location.i][location.j] != nullptr){
            location = randomLoc();
        }
        _grid[location.i][location.j] = new Predator(location.i,location.j);
    }
    
    
    
    
    
    

} //populates the grid with certain amount of prey and predators
void Grid::step(){
    for (int i = 1; i < 19; i++){
        for (int j = 1; j < 19; j++){
            if (_grid[i][j] != nullptr){

                _grid[i][j] -> move(_grid);
                
            }
            
        }
    }

    for (int i = 1; i < 19; i++){
        for (int j = 1; j < 19; j++){
            if (_grid[i][j] != nullptr){

                _grid[i][j] -> breed(_grid);
                
            }
            
        }
    }


    for (int i = 1; i < 19; i++){
        for (int j = 1; j < 19; j++){
            if (_grid[i][j] != nullptr){

                _grid[i][j] -> moved_false();
                
            }
        }
    }


} //double for loop, call the move function for each creature

bool Grid::all_alive(){
    for (int i = 1; i < 19; i++){
        for (int j = 1; j < 19; j++){
            if (_grid[i][j] == nullptr){

                return false;
                
            }
        }
    }
    return true;
}

bool Grid::any_alive(){
   
    for (int i = 1; i < 19; i++){
        for (int j = 1; j < 19; j++){
            if (_grid[i][j] != nullptr){

                return true;
                
            }
        }
    }
    return false;

} //returns true if creature count > 0

ostream& operator <<(ostream& outs, Grid g){

    
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
            cout << "|";
            if (g._grid[i][j]==nullptr){  
                cout << " ";

            }
            else{
                g._grid[i][j] ->print();
            }
        }
        cout << "|";
        cout << endl;        
    }
    return outs;
}
