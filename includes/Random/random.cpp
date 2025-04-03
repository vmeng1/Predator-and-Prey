
#include "../Random/random.h"
int randomNum(){
    
    return rand()%8;
    
}


Loc randomLoc(){

    return Loc(rand()%20,rand()%20);

}