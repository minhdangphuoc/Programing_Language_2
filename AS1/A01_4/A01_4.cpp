#include <iostream>
#include "Monster.h"

Monster medusa,zeus,apolo;

void setValue(){
    medusa.setValue('m',5,2);
    zeus.setValue('z',1,2);
    apolo.setValue('a',-1,-1);
    medusa.setStrength(20);
    zeus.setStrength(80);
    apolo.setStrength(50);
}

void printDatas(){
    for (int y = -10;y<10;y++){
        for (int x = -10;x<10;x++){
            if (x == medusa.xPosition&&y == medusa.yPosition){
                medusa.printSymbol();
            }
            else if (x == zeus.xPosition&&y == zeus.yPosition){
                zeus.printSymbol();
            }
            else if (x == apolo.xPosition&&y == apolo.yPosition){
                apolo.printSymbol();
            }
            else std::cout<<" _ ";
        }
        std::cout<<"\n";
    }

    medusa.printSymbol();
    std::cout<<medusa.getStrength()<<std::endl;
    
    zeus.printSymbol();
    std::cout<<zeus.getStrength()<<std::endl;
    
    apolo.printSymbol();
    std::cout<<apolo.getStrength()<<std::endl;
}

int main(){
    setValue();
    printDatas();
    return 0;
}