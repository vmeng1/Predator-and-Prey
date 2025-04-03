#ifndef LOC_H
#define LOC_H

#include <iostream>
#include <iomanip>
using namespace std;

struct Loc{
    int i;
    int j;
    Loc() : i(0), j(0){
        
    }
    Loc(int row, int col){
        i = row;
        j = col;
    }
    friend ostream& operator <<(ostream& outs, const Loc& loc){
        outs << "("<<loc.i<<", "<<loc.j<<")" ;
        return outs;
    }

};

#endif