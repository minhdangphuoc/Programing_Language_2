#include <iostream>
#include "GameObject.h"

int main(){

    //A06_1,2
    //symbol-value-pos X-pos Y
    Gem g1('*',10);
    //symbol-value-pos X-pos Y
    Monster m1('A',10);

    std::cout<<"\nGem: \nSymbol :"<< g1.getSymbol() << "\nValue :" << g1.getValue() << std::endl; 
    std::cout<<"\nMonster: \nSymbol :"<< m1.getSymbol() << "\nStrength :" << m1.getStrength() << std::endl;
    //std::cout<<"\nGem: \nSymbol :"<< g1.getSymbol() << "\nValue :" << g1.getValue() << "\nX,Y :"<< g1.getX() << ", " << g1.getY() << std::endl; 
    //std::cout<<"\nMonster: \nSymbol :"<< m1.getSymbol() << "\nStrength :" << m1.getStrength() << "\nX,Y :"<< m1.getX() << ", " << m1.getY() << std::endl; 
    
    //A06_2 public test
    Gem g2('*', 50, 1, 2);
    g2.print();

    //A06_3 private test
    Gem g3('*', 50, 1, 2);
    g3.printSymbol(); //Gem is child class of GameObject, so it can use function printSymbol (in public). Cannot recall after switching the inheritance type from public to private.
}