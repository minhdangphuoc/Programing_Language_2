#include <iostream>
class Position
{
private:
    /* data */
     int x, y;
public:

    void set(int x,int y){
        this -> x = x;
        this -> y = y;
    }
    
    void setX(int x){this -> x = x;};
    void setY(int y){this -> y = y;};
    int getX(){return x;};
    int getY(){return y;};
    
    bool equals(Position player){
        if (this -> x == player.getX() && this -> y == player.getY()) return true;
        return false;
    }

    friend bool operator == (const Position &p1,const Position &p2){
        if(p1.x==p2.x&&p1.y==p2.y) return true;
        return false;
    }
};

