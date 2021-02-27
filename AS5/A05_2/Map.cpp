#include <iostream>
#include <stdlib.h> 
#include "Map.h"
#include "time.h"

const int RANDOM = 4; //1 is highest change

//Constructor
Map::Map(int width, int height) {
    this -> width = width;
    this -> height = height;
    
    srand(time(NULL));
    map = new char [ this -> height * this -> width];
    for (int i = 0; i< this->height; i++){
        for (int k = 0; k < this->width; k++){
            if ((k%(this->width-1)==0||i%(this->height-1)==0)){
                map[i* this -> width + k] = '#';//wall build
            } else {
                map[i* this -> width + k] = (rand()%10==RANDOM?'#':'.');//random wall
            }
        }
    }
};
//deconstructor
Map::~Map(){
    delete[] map;
}


//Copy constructor
Map::Map(const Map &m){
    this -> width = m.width;
    this -> height = m.height;
    this -> map = m.map;
}


//Assignment operator
Map& Map::operator = (const Map &m) {
    height = m.height;
    width = m.width;
    map = m.map;
    return *this; 
}

//Operator constructor
Map operator + (const Map &m1, const Map &m2){
   return Map(m1.width+m2.width,m1.height+m2.height);
}


//Print table
void Map::print() {
    for (int i = 0; i < height; i++) {
        for (int k = 0; k < this->width; k++){
            
                std::cout<<map[i* this -> width + k];
        }
        std::cout<<"\n"; 
    }
}
