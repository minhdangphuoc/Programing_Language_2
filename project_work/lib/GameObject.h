#include "Position.h"
#include "Constants.h"
#include <time.h>

class GameObject
{
protected:
    Position pos;
    Constants ITEM;
public:
    int getX(){
        return pos.getX();
    }

    int getY(){
        return pos.getY();
    }

    void setX(int x){
        this -> pos.setX(x);
    }

    void setY(int y){
        this -> pos.setY(y);
    }

    virtual char getSymbol() = 0;

    virtual int getValue() = 0;

};

class Exit: public GameObject{
    public:
    Exit(int x, int y){
        pos.setX(x);
        pos.setY(y);
    }

    int getValue(){

    }

    char getSymbol(){
        return ITEM.SYMBOL_EXIT;
    }
 
};


class Player: public GameObject{
    public:
    
    Player(int max_x, int max_y){
        srand(time(NULL));
        pos.setX(rand()%max_x+1);
        pos.setY(rand()%max_y+1);
    }

    int getValue(){
        
    }

    char getSymbol() {
        return ITEM.SYMBOL_PLAYER;
    }
 
};

class Monster: public GameObject{
    private:
    int value;
    public:
    Monster(int x, int y){
        pos.setX(x);
        pos.setY(y);
        srand(time(NULL));
        value = (rand()%8+2)*5; //monsterdamage -10-50%
    }

    int getValue(){
        return value;
    }

    char getSymbol() {
        return ITEM.SYMBOL_MONSTER;
    }
    
};

class MagicApple: public GameObject{
    private:
    int value;
    public:
    MagicApple(int x, int y){
        pos.setX(x);
        pos.setY(y);
        srand(time(NULL));
        value = 50;
    }

    int getValue(){
        return value;
    }

    char getSymbol() {
        return ITEM.SYMBOL_MAGIC_APPLE;
    }
};

class Gem: public GameObject{
    private:
    int value, size;
    public:
    Gem(int x, int y){
        pos.setX(x);
        pos.setY(y);

        srand(time(NULL));
        size = rand()%3;
        switch(size){
            case 0:
                value = ITEM.VALUE_GEM_SMALL;
                break;
            case 1:
                value = ITEM.VALUE_GEM_MEDIUM;  
                break;
            case 2:
                value = ITEM.VALUE_GEM_BIG;  
                break;
        }
    }

    int getValue(){
        return this -> value;
    }

    char getSymbol(){
        switch(size){
            case 0:
                return ITEM.SYMBOL_GEM_SMALL;
                break;
            case 1:
                return ITEM.SYMBOL_GEM_MEDIUM;
                break;
            case 2:
                return ITEM.SYMBOL_GEM_BIG;
                break;
        }
    }
};

class Rock: public GameObject{
    public:
    Rock(int x, int y){
        pos.setX(x);
        pos.setY(y);
    }

    int getValue(){
        
    }

    char getSymbol() {
        return ITEM.SYMBOL_ROCK;
    }
};