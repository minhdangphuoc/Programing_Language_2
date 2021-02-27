#include <iostream>
#include "Position.h"

void Position::set(int x, int y){
    this -> x = x;
    this -> y = y;
}

void Position::setX(int x){

}

void Position::setY(int y){

}

int Position::getX() {return this -> x;}
    
int Position::getY() {return this -> y;}
    
bool Position::equals(Position player){
    if (this -> x == player.getX() && this -> y == player.getY()) return true;
    return false;
}

bool operator == (const Position &p1,const Position &p2){
    if(p1.x==p2.x&&p1.y==p2.y) return true;
    return false;
}

