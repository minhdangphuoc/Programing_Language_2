#include <iostream>
#include <stdlib.h> 
#include "time.h"
#include "GameObject.h"

class Map {
private:
	int width;
	int height;
	char* map;
public:
	//Assignment operator
	Map& operator = (const Map &m){
		height = m.height;
		width = m.width;
		map = m.map;
		return *this;
	}

	//Print table
	void print(){
		for (int i = 0; i < height; i++) {
        for (int k = 0; k < this->width; k++){
                std::cout<<map[i* this -> width + k];
        }
        std::cout<<"\n"; 
    	}
	}
	
	//Copy constructor
	Map(const Map &m){
		this -> width = m.width;
		this -> height = m.height;
		this -> map = m.map;
	}

	//Map testing 
	bool mapPlayable(){
		return false;
	}

	//Constructor
	Map(int width, int height, int difficulty){
		this -> width = width;
		this -> height = height;
		srand(time(NULL));

		map = new char [ this -> height * this -> width];
		for (int i = 0; i< this->height; i++){
			for (int k = 0; k < this->width; k++){
				if ((k%(this->width-1)==0||i%(this->height-1)==0)){
					map[i* this -> width + k] = '#';//wall build
				} else { //random opject
					map[i* this -> width + k] = (rand()%difficulty==0?'#':'.');//random wall
				}
			}
		}
	}

	~Map(){
		delete[] map;
	}
};