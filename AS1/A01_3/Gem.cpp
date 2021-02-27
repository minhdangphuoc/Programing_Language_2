#include <iostream>
#include "Gem.h"

void Gem::printSymbol(){
    std::cout<<symbol;
}

int Gem::getValue(){
    return value;
}

void Gem::gemGen(char inputSymbol, int inputValue){
    symbol = inputSymbol;
    value = inputValue;
}
