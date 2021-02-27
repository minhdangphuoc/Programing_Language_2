#include <iostream>
#include "Player.h"

Player::Player(int x, int y, int energy){
    player.set(x,y);
    this -> energy = energy;
}

Player::Player(){
    player.set(1,1);
    this -> energy = 100;
}