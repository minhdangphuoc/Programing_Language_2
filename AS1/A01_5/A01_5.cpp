#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>

struct GemStruct {
    
    char symbol;
    int value;

    void printSymbol(){
        std::cout<<symbol;
    }

    int getValue(){
        return value;
    }

    void gemGen(char inputSymbol, int inputValue){
        symbol = inputSymbol;
        value = inputValue;
    }
};

int sum(int x, int y){
    return x+y;
}

long int longSum (double x, double y){
    return static_cast<long int> (x+y);
}

void prettyPrint(double x, int p, int w){
    std::cout<<std::setprecision(p)<<std::fixed<<std::setw(w)<<x<<std::endl;
}

bool monsterDefeatedPlayer(int playerEnergy, int monsterEnergy){
    srand(time(0));
    if (playerEnergy>monsterEnergy){
        return false;
    } else return (rand()%2==0)?false:true;
}

int main(){
    //1
    std::cout<<sum(100,500)<<std::endl;

    //2
    std::cout<<longSum(12.5,50.7)<<std::endl;

    //3
    prettyPrint(12.3456,2,10);
    
    //4
    std::cout<<(monsterDefeatedPlayer(0,50)==true?("true"):("false"))<<std::endl;
    std::cout<<(monsterDefeatedPlayer(50,10)==false?("true"):("false"))<<std::endl;

    //5
    GemStruct gem1,gem2,gem3;
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