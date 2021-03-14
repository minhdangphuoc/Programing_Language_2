#include <iostream>
#include "GameObject.h"

class player:public GameObject{
    public:
    player(int x,int y):GameObject(x,y){}
};

int main(){
    //A07_5_1
    GameObject *base = new Monster(40,40);//run this code
    base -> print();//run this code
    delete base;//run this code

    //A07_5_2
    MagicApple a(10,10);
    a.print(); 

    //A07_5_3
    const int leng = 5;
    GameObject* myGameObjects[leng];
    myGameObjects[0] = new Monster(100,100);
    myGameObjects[1] = new Monster(10,10);
    myGameObjects[2] = new MagicApple(10,10);
    myGameObjects[3] = new MagicApple(1,1);
    myGameObjects[4] = new MagicApple(1,10);
    for (int i = 0; i< 5;i++){
        myGameObjects[i]->print();
    }
    
    //A07_5_4
    GameObject g(1,1);
    Monster m(2,2);
    std::cout<<"g type:"<< g.getType() <<std::endl;
    std::cout<<"m type:"<< m.getType() <<std::endl;
    std::cout<<"a type:"<< a.getType() <<std::endl;

    //A07_5_4
    player p(10,10);
    for (int i = 0; i< 5;i++){
         if (p == *myGameObjects[i]){
                switch (myGameObjects[i]->getType())
                {
                case 0:
                    std::cout<<"<Player sees a game object>"<<std::endl;
                    break;
                case 1:
                    std::cout<<"<Player sees a monster>"<<std::endl;
                    break;
                case 2:
                    std::cout<<"<Player sees a magic apple>"<<std::endl;
                    break;
                }
         }
    }
    for (int i = 0; i< 5;i++){
        delete myGameObjects[i];
    }
}