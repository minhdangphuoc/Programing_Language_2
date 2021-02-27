#include <iostream>
#include <cstddef>
#include "Gem.h"

void Gem::printSymbol(){
    std::cout<<symbol;
}

int Gem::getValue(){
    return value;
}

Gem::Gem(char inputSymbol, int inputValue){
    symbol = inputSymbol;
    value = inputValue;
}

Gem::Gem(char inputSymbol){
    symbol = inputSymbol;
}
