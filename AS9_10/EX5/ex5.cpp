#include <iostream>
#include <vector>
//A10_2
class GameObject{
    public:
    virtual void printSelf() = 0;
};

class Monster:public GameObject{
    private:
    int strength;
    public:
    Monster(int strength){
        this -> strength = strength;
    }
    void printSelf() {
        std::cout<<"I am a monster with strength "<<strength<<std::endl;
    }
};

class Gem:public GameObject{
    private:
    int value;
    public:
    Gem(int value){
        this -> value = value;
    }
    void printSelf() {
        std::cout<<"I am a gem with value "<<value<<std::endl;
    }
};



int main(){
    Monster m1(77);  // A monster with strength 77.

    Gem g1(100);  // A gem with value 100.

    m1.printSelf();  // Prints "I am a monster with strength 77".

    g1.printSelf();  // Prints "I am a gem of value 100".

}