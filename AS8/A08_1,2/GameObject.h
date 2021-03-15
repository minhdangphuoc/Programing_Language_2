#include <iostream>
#include "Position.h"

#define quote(x) #x

class GameObject
{
private:
    char symbol;
protected:
    
    Position position; //protected class member
public:
    enum ObjectType { GameObjectType, MonsterType, MagicAppleType };
    void setSymbol(char symbol){
        this -> symbol = symbol;
    }
    virtual ObjectType getType(){
        return GameObjectType;
    }
    virtual void printSelf(){
        std::cout << "GameObject is at "<<position.getX()<<", "<<position.getY()<<"(in GameObject)"<<std::endl;
    }
    
    char getSymbol(){
        return this -> symbol;
    }

    void print();

    void printSymbol(){
        std::cout << "\n" << symbol << "\n"; 
    }

    int getX(){
        return position.getX();
    }

    int getY(){
        return position.getY();
    }

    friend bool operator == (const GameObject &g1,const GameObject &g2){
        return g1.position == g2.position;
    }


    GameObject(int x, int y){
        std::cout<<"\nGameObject constructor\n";
        position.setX(x);
        position.setY(y);
    }

    GameObject(char symbol, int x, int y){
        position.setX(x);
        position.setY(y);
        this -> symbol = symbol;
    }

    GameObject(char symbol){
        this -> symbol = symbol;
    }
    GameObject(){}
    ~GameObject(){
        std::cout<<"\nGameObject destructor\n";
    }
};

class MagicApple : public GameObject{
    public:

    MagicApple(int x, int y):GameObject(x,y){
        std::cout << "\nMonster constructor\n";
    }

    virtual ObjectType getType(){
        return MagicAppleType;
    }

    void printSelf(){
        std::cout << "Magic Apple is at "<<position.getX()<<", "<<position.getY()<<"(in MagicApple)"<<std::endl;
    }
};


//publicly inherit GameObject
class Monster : public GameObject{
private:
    int strength;
public:
    void roar(){ //print Aaaaaaarrr
        std::cout<<"AAaaarrr!!"<<std::endl;
    }

    int getStrength(){return strength;}
    void setStrength(int strength){this -> strength = strength;}

    void printSelf(){
        std::cout << "Monster is at "<<position.getX()<<", "<<position.getY()<<"(in Monster)"<<std::endl;
    }

    Monster(char symbol,int strength, int x, int y):GameObject(symbol,x,y){
        std::cout<<"\nMonster constructor\n";
        this -> strength = strength;
    }

    Monster(char symbol, int x, int y):GameObject(symbol,x,y){};

    Monster(int x, int y):GameObject(x,y){
        std::cout<<"\nMonster constructor\n";
    }

    Monster(char symbol,int strength):GameObject(symbol){
        this -> strength = strength;
    }

    virtual ObjectType getType(){
        return MonsterType;
    }

    ~Monster(){
        std::cout<<"\nMonster destructor\n";
    }
};

void GameObject::print(){
    printSelf();
}