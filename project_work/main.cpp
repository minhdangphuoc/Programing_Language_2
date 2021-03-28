#include <iostream>
#include "lib/Map.h"

void gameLoop(){
    
    gameLoop();
}

int main(){
    Map * m;
    do
    {
        m = new Map(10,10,5);
    } while (m->mapPlayable());
    
    m->print();
}