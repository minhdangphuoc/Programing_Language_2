#include <iostream>
#include "Position.h"

class GameObject
{
private:
    Position position; //private class member
    char symbol;
public:
    void setSymbol(char symbol){
        this -> symbol = symbol;
    }
    
    char getSymbol(){
        return this -> symbol;
    }

    void printSymbol(){
        std::cout << "\n" << symbol << "\n"; 
    }

    int getX(){
        return position.getX();
    }

    int getY(){
        return position.getY();
    }

    GameObject(char symbol, int x, int y){
        std::cout<<"\nGameobject constructor\n";
        position.setX(x);
        position.setY(y);
        this -> symbol = symbol;
    }

    GameObject(char symbol){
        std::cout<<"\nGameobject constructor\n";
        this -> symbol = symbol;
    }

    ~GameObject(){
        std::cout<<"\nGameObject destructor\n";
    }
};

//publicly inherit GameObject
class Gem : public GameObject{
private:
    int value;
public:
    int getValue(){return value;}
    void setValue(int value){this -> value = value;}

    Gem(char symbol,int value, int x, int y):GameObject(symbol,x,y){
        this -> value = value;
        std::cout<<"\nGem constructor\n";
    }

    Gem(char symbol,int value):GameObject(symbol){
        this -> value = value;
        std::cout<<"\nGem constructor\n";
    }

    //A06_2
    void print(){
        std::cout<<"\nGem: \nSymbol :"<< getSymbol() << "\nValue :" << getValue() << "\nX,Y :"<< getX() << ", " << getY() << std::endl; 
    }

    ~Gem(){
        std::cout<<"\nGem destructor\n";
    }
};

//publicly inherit GameObject
class Monster : public GameObject{
private:
    int strength;
public:
    int getStrength(){return strength;}
    void setStrength(int strength){this -> strength = strength;}

    Monster(char symbol,int strength, int x, int y):GameObject(symbol,x,y){
        std::cout<<"\nMonster constructor\n";
        this -> strength = strength;
    }

    Monster(char symbol,int strength):GameObject(symbol){
        std::cout<<"\nMonster constructor\n";
        this -> strength = strength;
    }


    ~Monster(){
        std::cout<<"\nMonster destructor\n";
    }
};
