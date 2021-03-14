#include <iostream>
#include "GameObject.h"

void process(GameObject &object){
    object.printSelf();
}

int main(){
    //A07_1
    GameObject g(1,1);
    Monster m(2,2);
    g.printSelf(); //run this code (delete //)
    m.printSelf(); //run this code 
    //output
    //GameObject is at 1, 1
    //Monster is at 2, 2

    //A07_2-Early binding
    //delete virtual GameObject::printSelf()
    g.print(); //run this code
    m.print(); //run this code
    //output 
    //GameObject is at 1, 1(in GameObject) <- access to GameObject::printSelf(), GameObject::position.getX(), GameObject::position.getY()
    //GameObject is at 2, 2(in GameObject) <- access to GameObject::printSelf(), Monster::position.getX(), Monster::position.getY()

    //A07_3 add virtual before printSelf() - Early binding
    g.print(); //run this code
    m.print(); //run this code
    //GameObject is at 1, 1(in GameObject) <- access to GameObject::printSelf(), GameObject::position.getX(), GameObject::position.getY()
    //Monster is at 2, 2(in Monster) <- access to Monster::printSelf(), Monster::position.getX(), Monster::position.getY()

    //A07_4
    process(g); //run this code
    process(m); //run this code
    //GameObject is at 1, 1(in GameObject) <- access to GameObject::printSelf(), GameObject::position.getX(), GameObject::position.getY()
    //Monster is at 2, 2(in Monster) <- access to Monster::printSelf(), Monster::position.getX(), Monster::position.getY()
    

}
