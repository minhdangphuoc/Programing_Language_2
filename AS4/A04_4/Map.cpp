#include <iostream>
#include "Map.h"

//Constructor
Map::Map(int w, int h) {
    width = w;
    height = h;
    row = new char [h];
    for (int k = 0; k < h; k++) {
        row[k] = '*';
    }
    
}; 

//Print table
void Map::print() {
    for (int i = 0; i < height; i++) {
            std::cout << std::string(width,row[i])<<std::endl;  
    }
}
