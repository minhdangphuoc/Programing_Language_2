#include <iostream>
#include <utility>
#include "Gem.h"
#include "Constants.h"

int main(){
    //EX1
    Gem myGem(107); //Introduce and initialize a fixed gem
    myGem.setValue(40); //Change the value of myGem by using setValue setter
    std::cout<<&myGem<<std::endl;
    
    //Introduce an another pointer and dynamically allocate another Gem named myGem2
    Gem* myGem2; //
    myGem2 = new Gem(50);//

    myGem2->setValue(20);//std::cout<<&myGem<<std::endl;
    std::cout<<&myGem<<std::endl;//Print Address
    delete myGem2;//delete

    //EX2
    Gem gems[3]{Gem(12),Gem('*',30),Gem('o')};
    
    std::cout<<"Gem 1: ";
    gems[0].printSymbol();
    std::cout<<gems[0].getValue()<<std::endl;
    
    std::cout<<"Gem 2: ";
    gems[1].printSymbol();
    std::cout<<gems[1].getValue()<<std::endl;
    
    std::cout<<"Gem 3: ";
    gems[2].printSymbol();
    std::cout<<gems[2].getValue()<<std::endl;

    //EX3
    const int SIZE = 3;
    std::cout<< "Dynamic array, fixed gems" << std::endl; 

    Gem* gemArray = new Gem [SIZE];
    
    for (int i = 0; i < SIZE; ++i){
        gemArray[i] = Gem(100*i);
        std::cout << "Gem " << i + 1<< ": " << gemArray[i].getValue() <<std::endl;
    }
    //delete[] gemArray;

    //EX4
    std::cout<< "Dynamic array, fixed gems" << std::endl; 
    
    typedef Gem* tGemPtr;
    tGemPtr* gemPtrArray = new tGemPtr[SIZE];
    
    for (int i = 0; i < SIZE; ++i){
        gemPtrArray[i] = new Gem(200*i);
        std::cout << "Gem " << i + 1<< ": " << gemPtrArray[i]->getValue() << std::endl; 
    }

    for (int i = 0; i < SIZE; ++i) delete gemPtrArray[i];
    delete[] gemPtrArray;

    //EX5
    std::cout<< "Constructed gems: " << myGem.getObjectCount() << std::endl; 
    
    std::cout<< "Destroyed gems: " << myGem.getDeletedCount() << std::endl;
}