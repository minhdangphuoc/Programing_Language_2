#include <iostream>
#include "Gem.h"

int main(){
    //Create an opject of Gem
    Gem gem1('*',50);
    Gem gem2('*');

    // Print Value
    std::cout<< "Gem 1: ";
    gem1.printSymbol();
    std::cout<< " " << gem1.getValue() << std::endl;

    std::cout<< "Gem 2: ";
    gem2.printSymbol();
    std::cout<< " " << gem2.getValue() << std::endl;

}