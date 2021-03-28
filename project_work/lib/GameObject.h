#include "Position.h"
class GameObject
{
protected:
    Position pos;
public:
};

class Player: public GameObject{
    private:
    int energy,point;
    public:
    Player(int x, int y, int energy, int point){
        pos.setX(x);
        pos.setY(y);
        this -> energy = energy;
        this -> point = point;
    }
};

class Monster: public GameObject{

};

class MagicApple: public GameObject{

};

class Gem: public GameObject{

};

class Rock: public GameObject{

};