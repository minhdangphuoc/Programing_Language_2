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
};

class Player: public GameObject{
    public:
    Player(int max_x, int max_y){
        srand(time(NULL));
        pos.setX(rand()%max_x+1);
        pos.setY(rand()%max_y+1);
    }

    char getSymbol(){
        return ITEM.SYMBOL_PLAYER;
    }
 
};

class Monster: public GameObject{
};

class MagicApple: public GameObject{
};

class Gem: public GameObject{
};

class Rock: public GameObject{
    public:
    Rock(int x, int y){
        pos.setX(x);
        pos.setY(y);
    }
    char getSymbol(){
        return ITEM.SYMBOL_ROCK;
    }

};