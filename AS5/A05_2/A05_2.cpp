#include <iostream>
#include "Map.h"
//Objective 
//Create map class
//Print


int main(){
    Map m1(5,10);
    Map m2(6,5);
    Map m3 = m2;
    m3.print();
    m3 = m1;
    m3.print();

}