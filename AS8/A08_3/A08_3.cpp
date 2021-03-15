#include <iostream>
#include "Position.h"
class Movable {
    public:
    virtual void setPosition (Position p) = 0;
    virtual Position getPosition() = 0;
};

class Valuable {
    public:
    virtual int getValue() = 0;
};

class MagicLamp: public Movable, public Valuable{
    private:
    Position p;
    public:

    MagicLamp(Position p){
        this -> p = p;
    }
    void setPosition (Position p){
        this -> p = p;
    };
    Position getPosition(){
        std::cout<<"\nPosition:"<<p.getX()<<" "<<p.getY();
        return p;
    };
    int getValue(){
        return 5;
    }
};

int main(){
    Position P1(2,2) ;
    Position P2(5,5);
    MagicLamp lamp(P1);
    Movable* move = new MagicLamp(P1) ;
    Valuable* value = new MagicLamp(P1) ;
    move ->getPosition() ;
    std::cout <<"\nValue:"<< value ->getValue() << std::endl ;

    move ->setPosition(P2); // change position from P1 to P2
    move ->getPosition(); 
    std::cout <<"\nValue:"<< value ->getValue() << std::endl ;
    
}
