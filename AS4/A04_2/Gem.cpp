#include <iostream>
#include <cstddef>
#include "Gem.h"

void Gem::printSymbol(){
    std::cout<<symbol;
}

int Gem::getValue(){
    return *value;
}

int Gem::getObjectCount() {return objectCounter;}

Gem::Gem(char inputSymbol, int inputValue){
    symbol = new char;
    value = new int;
    this->objectCounter++;
    *symbol = inputSymbol;
    *value = inputValue;
}

Gem::Gem(char inputSymbol){
    symbol = new char;
    value = new int;
    this->objectCounter++;
    *symbol = inputSymbol;
}

Gem::~Gem(){
    std::cout<<"\nDeconstruct successful"<<std::endl; 
    delete symbol;
    delete value;
}

int Gem::objectCounter = 0;