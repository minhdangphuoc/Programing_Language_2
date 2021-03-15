#include <iostream>
#include "GameObject.h"

int main(){ 
    //A08_1
    GameObject *g = new GameObject();
    Monster* m = static_cast<Monster*>( g );
    m->roar();
    delete g;

    Monster *m2 = new Monster('&', 3, 4);//Monster pointer
    GameObject *g2 = nullptr; //GameObject pointer
    g2 = m2; //pointer = pointer
    Monster* m3 = static_cast<Monster*>(g2);// 
    m3->roar(); 
    delete m3,m2,g2;

    //A08_2
    // When change GameObject to abstract class, 
    //the function in A08_1 will get error 
    //GameObject cannot be instantiated
    //GameObject* m1 = new Monster();
    //m1 -> makeSound();
    /*An abstract class is the class that has at least one abstract method. 
    The abstract methods are virtual methods with the value = 0
    You can not create an instance of abstract class, you only can create an instance of child class.
    If a class inherits from a abstract class, this class has to override all the methods in abstract class. */
}