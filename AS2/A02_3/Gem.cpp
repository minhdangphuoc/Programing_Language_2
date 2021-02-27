#include <iostream>
#include <cstddef>
#include "Gem.h"

void Gem::printSymbol(){
    std::cout<<symbol;
}

int Gem::getValue(){
    return *value;
}

Gem::Gem(char inputSymbol, int inputValue){
    symbol = new char;
    value = new int;
    
    *symbol = inputSymbol;
    *value = inputValue;
}

Gem::Gem(char inputSymbol){
    symbol = new char;
    value = new int;
    
    *symbol = inputSymbol;
}

Gem::~Gem(){
    std::cout<<"Deconstruct successful"<<std::endl; 
    delete symbol;
    delete value;
}