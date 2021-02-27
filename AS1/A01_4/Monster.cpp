#include <iostream>
#include "Monster.h"

void Monster::printSymbol(){
    std::cout<<" "<<symbol<<" ";
}

void Monster::setValue(char inputSymbol, int inputX, int inputY){
    symbol = inputSymbol;
    xPosition = inputX;
    yPosition = inputY;
}

void Monster::setStrength(int inputStrength){
    strength = inputStrength;
}

int Monster::getStrength(){
    return strength;
}