#include <iostream>
#include <stdlib.h> 
#include "time.h"
#include "GameObject.h"

class Map {
private:
	int width;
	int height;
	char* map;
	char* objectPosCode;
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
	
	void setObject(const char symbol, int code){

	}

	//Operator constructor
	friend Map operator + (Map const &, Map const &);
	
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
	Map(int width, int height){
		this -> width = width;
		this -> height = height;
		srand(time(NULL));

		map = new char [ this -> height * this -> width];
		for (int y = 0; y< this->height; y++){
			for (int x = 0; x < this->width; x++){
				if ((x%(this->width-1)==0||y%(this->height-1)==0)){
					map[y* this -> width + x] = '#';//wall build
				}
			}
		}
	}

	~Map(){
		delete[] map;
	}
};
