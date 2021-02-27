#include <iostream>
#include "Player.h"

int main(){
    Player p1(3,3,90),p2;
    std::cout<<p1.player.getX()<<"\n";
    std::cout<<p1.player.getY()<<"\n";
    std::cout<<p1.getE()<<"\n";
    std::cout<<p2.player.getX()<<"\n";
    std::cout<<p2.player.getY()<<"\n";
    std::cout<<p2.getE()<<"\n";

}