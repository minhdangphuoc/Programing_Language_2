#include <iostream>
#include "Gem.h"

int main(){
    const int MAX_SIZE=5;

    //Create an opject of Gem
    Gem gem[MAX_SIZE]={Gem('*',5),Gem('*'),Gem('*',25),Gem('-',35),Gem('^',45)};

    // Print Value
    for (int i =0;i<MAX_SIZE;i++){
        std::cout<< "Gem "<<i+1<<": ";
        gem[i].printSymbol();
        std::cout<< " " << gem[i].getValue() << std::endl;
    }

}