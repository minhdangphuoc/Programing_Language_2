#include <iostream>
#include <utility>
#include <cstddef>
#include "Gem.h"

void Gem::printSymbol(){
    std::cout<<symbol;
}

int Gem::getValue(){
    return *value;
}

void Gem::setValue(int value){
    * this -> value = value;
}

int Gem::getDeletedCount(){return deletedCounter;}

int Gem::getObjectCount() {return objectCounter;}

//Constructor
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
    this -> objectCounter++;
    *symbol = inputSymbol;
}

Gem::Gem(int value){
    this -> value = new int;
    this -> symbol = new char;
    this -> objectCounter++;
    
    * this -> value = value;
}

Gem::Gem(){}

//Destructor
Gem::~Gem(){
    this -> deletedCounter++;
    std::cout<<"\n-Deleted-\n";
    delete symbol;
    delete value;
}

int Gem::deletedCounter =0;
int Gem::objectCounter = 0;