#include <iostream>
#include <stdlib.h> 
#include "time.h"

class Map {
private:
	int width;
	int height;
	char* map;
	int* objectPosCode;
	
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
		for (int y = 0; y < this -> height; y++) {
        for (int x = 0; x < this -> width; x++){
                std::cout<<map[y * this -> width + x];
        }
        std::cout<<"\n"; 
    	}
	}

	bool isWall(const int x, const int y){
		return map[y* this -> width + x]=='X'?true:false;
	} 

	bool isApple(const int x, const int y){
		return map[y* this -> width + x]=='X'?true:false;
	} 

	bool isGem(const int x, const int y){
		if(map[y* this -> width + x]=='*'||map[y* this -> width + x]=='$'||map[y* this -> width + x]=='#')
		{
			return true;
		}
		return false;
		
	} 

	char getObject(const int x, const int y){
		return map[y* this -> width + x];
	}

	char getCode(const int x, const int y){
		return objectPosCode[y* this -> width+ x];
	}

	void setObject(const int x, const int y,const char symbol, const int code){
		map[y* this -> width+ x] = symbol;
		objectPosCode[y* this -> width+ x] = code;
	}

	void clearObject(const int x, const int y){
		map[y* this -> width+ x] = '.';
	}

	//Constructor
	Map(int width, int height){
		this -> width = width;
		this -> height = height;
		srand(time(NULL));

		map = new char [ this -> height * this -> width];
		objectPosCode = new int [ this -> height * this -> width];
		for (int y = 0; y< this->height; y++){
			for (int x = 0; x < this->width; x++){
				if ((x%(this->width-1)==0||y%(this->height-1)==0)){
					map[y* this -> width + x] = 'X';//wall build
				} else map[y* this -> width + x] = '.';
			}
		}
	}

	~Map(){
		delete map, objectPosCode;
	}
};
