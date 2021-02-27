#include <iostream>
#include "Position.h"

int main(){
    Position p1,p2;
    p1.set(10,10);
    p2.set(10,9);
    std::cout<<(p1==p2);
}