#include <iostream>
#include "Gem.h"

int main(){
    Gem gem1,gem2,gem3;
    gem1.gemGen('*',50);
    gem2.gemGen('*',75);
    gem3.gemGen('O',150);

    std::cout<< "Gem 1: ";
    gem1.printSymbol();
    std::cout<< " " << gem1.getValue() << std::endl;

    std::cout<< "Gem 2: ";
    gem2.printSymbol();
    std::cout<< " " << gem2.getValue() << std::endl;

    std::cout<< "Gem 3: ";
    gem3.printSymbol();
    std::cout<< " " << gem3.getValue() << std::endl;
}