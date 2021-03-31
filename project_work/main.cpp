#include <iostream>
#include "lib/GameObject.h"
#include "lib/Map.h"
#include <time.h>

const int MAX_LEVEL=10;

struct Move
{
    int x;
    int y;
} w_move, a_move, s_move, d_move;

struct LEVEL{
    int HEIGHT, WIDTH, MONSTERS, GEMS, MAGICAPPLES, ROCKS;
} E_LEVEL[MAX_LEVEL];

const std::string menu[2] =  {"╔═════════════════════════════════════════════╗"
                            "\n║Welcome to the Treasure Hunt!                ║"
                            "\n║Entered into the magical dungeon, good luck! ║"
                            "\n║Choose your options below:                   ║"
                            "\n║1. Play                                      ║"
                            "\n║2. Exit the program                          ║"
                            "\n╚═════════════════════════════════════════════╝"
                            "\nYour option: ",
                              "/////////////////////////////////////////////////"
                        	"\n//Welcome to the Treasure Hunt!                //"
                            "\n//Entered into the magical dungeon, good luck! //"
                            "\n//Choose your options below:                   //"
                        	"\n//1. Play                                      //"
                            "\n//2. Exit the program                          //"
                        	"\n/////////////////////////////////////////////////"
                        	"\nYour option: "};

void defaultConfig(){
    for(int i=0; i<MAX_LEVEL; i++){
        E_LEVEL[i].HEIGHT = 7+i;
        E_LEVEL[i].WIDTH = 7+i;
        E_LEVEL[i].MONSTERS = (i/2)+1;
        E_LEVEL[i].GEMS = (i/3)*2+1;
        E_LEVEL[i].MAGICAPPLES = (i/2)+1;
        E_LEVEL[i].ROCKS = 3*(i+1);
    }
}

void playerDead(){
    if (system("CLS")) system("clear"); 
    std::cout<<"Game Over\nPress enter to exit.\n";
    std::cin.ignore();
    std::cin.get();
    if (system("CLS")) system("clear"); 
    exit(0);
}

void showEnergy(int energy){
    for (int i =1; i <= energy/5 ; i++) std::cout<<"#";
    for (int i =1; i <= (100-energy)/5; i++) std::cout<<" ";
    std::cout<<" "<<energy<<"%";
}

void gameLoop(const int level, int energy, int point){
    srand(time(NULL));
    bool finish = false, nextLevel = false;
    char opt;
    int x_temp, y_temp;
    //GAMEOPJECT CREATED
    //PLayer and Map
    Player * p = new Player(E_LEVEL[level].HEIGHT-2,E_LEVEL[level].WIDTH-2);
    Map * m = new Map(E_LEVEL[level].HEIGHT,E_LEVEL[level].WIDTH);
    m->setObject(p->getX(),p->getY(),p->getSymbol(),0); //set player on Map
    
    //Rock
    GameObject * r[E_LEVEL[level].ROCKS];
    for (int i = 0; i< E_LEVEL[level].ROCKS; i++){
        do{//Free check
            x_temp = 1+rand()%(E_LEVEL[level].HEIGHT-2);
            y_temp = 1+rand()%(E_LEVEL[level].WIDTH-2);
        } while (m->getObject(x_temp, y_temp)!='.');

        r[i] = new Rock(x_temp,y_temp);
        m->setObject(r[i]->getX(), r[i]->getY(), r[i]->getSymbol(), i);
        //std::cout<<"ROCK: "<<i<<" "<<r[i]->getX()<<" "<<r[i]->getY()<<" "<<r[i]->getSymbol()<<std::endl;
    }

    //Gem
    GameObject * gems[E_LEVEL[level].GEMS];
    for (int i = 0; i< E_LEVEL[level].GEMS; i++){
        do{//Free check
            x_temp = 1+rand()%(E_LEVEL[level].HEIGHT-2);
            y_temp = 1+rand()%(E_LEVEL[level].WIDTH-2);
        } while (m->getObject(x_temp, y_temp)!='.');
        gems[i] = new Gem(x_temp,y_temp);
        m->setObject(gems[i]->getX(), gems[i]->getY(), gems[i]->getSymbol(), i);
        //std::cout<<"GEM: "<<i<<" "<<gems[i]->getX()<<" "<<gems[i]->getY()<<" "<<gems[i]->getSymbol()<<std::endl;
    }
    
    //Gem
    GameObject * M_Apples[E_LEVEL[level].MAGICAPPLES];
    for (int i = 0; i< E_LEVEL[level].MAGICAPPLES; i++){
        do{//Free check
            x_temp = 1+rand()%(E_LEVEL[level].HEIGHT-2);
            y_temp = 1+rand()%(E_LEVEL[level].WIDTH-2);
        } while (m->getObject(x_temp, y_temp)!='.');
        M_Apples[i] = new MagicApple(x_temp,y_temp);
        m->setObject(M_Apples[i]->getX(), M_Apples[i]->getY(), M_Apples[i]->getSymbol(), i);
        //std::cout<<"GEM: "<<i<<" "<<gems[i]->getX()<<" "<<gems[i]->getY()<<" "<<gems[i]->getSymbol()<<std::endl;
    }

    
    do{
        std::cout<<"Level: "<<level+1<<"\nPlayer energy: ";
        showEnergy(energy);
        std::cout<<"\nPoints: "<<point<<"\n";
        m->print();
        if(energy == 0) playerDead();
        std::cout<<"Please select action: ";
        std::cin>>opt;

        energy-=5;

        switch (opt)
        {
        case 'w':
            /* code */
            if (m->isWall(p->getX(),p->getY()-1)){
                //to player function
                std::cout<<"Hit the wall. Try Again. \nPress enter to continue!";
                std::cin.ignore();
                std::cin.get();
                energy+=5; //-> to player
                break;
            }

            m->clearObject(p->getX(),p->getY());
            p->setY(p->getY()-1);
            if (m->getObject(p->getX(),p->getY())=='E') {
                finish = true;
            } else if (m->isGem(p->getX(),p->getY())){
                E_LEVEL[level].GEMS--;
                point+=gems[m->getCode(p->getX(),p->getY())]->getValue();
            } else if (m->getObject(p->getX(),p->getY())=='a'){
                energy = energy+M_Apples[m->getCode(p->getX(),p->getY())]->getValue();
            }
            m->setObject(p->getX(),p->getY(),p->getSymbol(),0);
            break;
        case 'a':
            
            if (m->isWall(p->getX()-1,p->getY())){
                std::cout<<"Hit the wall. Try Again. \nPress enter to continue!";
                std::cin.ignore();
                std::cin.get();
                energy+=5;
                break;
            }

            m->clearObject(p->getX(),p->getY());//
            p->setX(p->getX()-1); //goleft function::Player
            if (m->getObject(p->getX(),p->getY())=='E') {
                finish = true;
            } else if (m->isGem(p->getX(),p->getY())){
                E_LEVEL[level].GEMS--;
                point+=gems[m->getCode(p->getX(),p->getY())]->getValue();                
            } else if (m->getObject(p->getX(),p->getY())=='a'){
                energy = energy+M_Apples[m->getCode(p->getX(),p->getY())]->getValue();
            }
            
            m->setObject(p->getX(),p->getY(),p->getSymbol(),0);
            break;
        case 's':
            
            if (m->isWall(p->getX(),p->getY()+1)){
                std::cout<<"Hit the wall. Try Again. \nPress enter to continue!";
                std::cin.ignore();
                std::cin.get();
                energy+=5;
                break;
            }

            m->clearObject(p->getX(),p->getY());
            p->setY(p->getY()+1);
            if (m->getObject(p->getX(),p->getY())=='E') {
                finish = true;
            } else if (m->isGem(p->getX(),p->getY())){
                E_LEVEL[level].GEMS--;
                point+=gems[m->getCode(p->getX(),p->getY())]->getValue();                
            } else if (m->getObject(p->getX(),p->getY())=='a'){
                energy = energy+M_Apples[m->getCode(p->getX(),p->getY())]->getValue();
            }

            m->setObject(p->getX(),p->getY(),p->getSymbol(),0);
            break;
        case 'd':
            
            if (m->isWall(p->getX()+1,p->getY())){
                std::cout<<"Hit the wall. Try Again. \nPress enter to continue!";
                std::cin.ignore();
                std::cin.get();
                energy+=5;
                break;
            }
            
            m->clearObject(p->getX(),p->getY());
            p->setX(p->getX()+1);
            if (m->getObject(p->getX(),p->getY())=='E') {
                finish = true;
            } else if (m->isGem(p->getX(),p->getY())){
                E_LEVEL[level].GEMS--;
                point+=gems[m->getCode(p->getX(),p->getY())]->getValue();
            } else if (m->getObject(p->getX(),p->getY())=='a'){
                energy = energy+M_Apples[m->getCode(p->getX(),p->getY())]->getValue();
            }

            m->setObject(p->getX(),p->getY(),p->getSymbol(),0);
            break;
        default:
            energy+=5;
            std::cout<<"Wrong input.\nPress enter to continue!";
            std::cin.ignore();
            std::cin.get();
            break;
        }
        
        if (energy>100) energy = 100; //no higher than 100

        if(E_LEVEL[level].GEMS==0&&nextLevel == false){
            nextLevel = true;
            //Exit
            do{//Free check //tranfer to map class###########
                x_temp = 1+rand()%(E_LEVEL[level].HEIGHT-2);
                y_temp = 1+rand()%(E_LEVEL[level].WIDTH-2);
            } while (m->getObject(x_temp, y_temp)!='.');
            
            GameObject * exit = new Exit(x_temp,y_temp);
            m->setObject(exit->getX(), exit->getY(), exit->getSymbol(), 0);
        }

        if (system("CLS")) system("clear"); 
    }while(!finish);

    //FREE SPACE
    delete p,m,exit;
    for (int i = 0; i < E_LEVEL[level].ROCKS; i++){
        delete [] r[i];
    }

    if (level == MAX_LEVEL) {playerDead();};
    gameLoop(level+1,energy,point);
}


void menuSelection(const bool OSmode){
    char opt;
    std::cout<<menu[OSmode];
    std::cin>>opt;

    if (system("CLS")) system("clear");
    
    switch (opt)
    {
    case '1':
        /* code */
        gameLoop(0,100,0);
        break;
    case '2':
        std::cout<<"Good Bye, See you again.\n";
        //Pause for showing the player list
        std::cout<<"Press enter key to exit. ";
        //std::cin.get();
        std::cin.ignore();
        std::cin.get();
        if (system("CLS")) system("clear");
        system("exit");
        exit (0);
        break;

    default:
        break;
    }
    menuSelection(OSmode);
}

void OS_select(){
    char opt;
    std::cout<<"Choose your main OS:\n1. Window with CMD\n2. Linux/Macos with terminal\nYour option: ";
    std::cin>>opt;

    if (system("CLS")) system("clear");//Clear screen

    switch (opt)
    {
    case '1':
        menuSelection(1);    
        break;
    case '2':
        menuSelection(0);  
        break;

    default:
        std::cout<<"\nError input\n";
        
        OS_select();
    }

}

int main(){
    if (system("CLS")) system("clear");
    defaultConfig();
    OS_select();  
}