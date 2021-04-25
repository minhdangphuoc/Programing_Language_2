#include <iostream>
#include "lib/GameObject.h"
#include "lib/Map.h"
#include <time.h>

void OS_select();

const int MAX_LEVEL=10;

const int move_x[5] = {0,0,-1,0,1};
const int move_y[5] = {0,-1,0,1,0};

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
        E_LEVEL[i].MAGICAPPLES = (i/4)+1;
        E_LEVEL[i].ROCKS = 3*(i+1);
    }
}

void endGame(){
    char opt;
    if (system("CLS")) system("clear"); 
    std::cout<<"Play again (y/n):";
    std::cin>>opt;
    if (system("CLS")) system("clear"); 
    if(opt=='y'){
        
        OS_select();
    }
    
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
    int x_temp, y_temp, input=0;
    //GAMEOPJECT CREATED
    //PLayer and Map
    Player * p = new Player(E_LEVEL[level].HEIGHT-2,E_LEVEL[level].WIDTH-2);
    Map * m = new Map(E_LEVEL[level].HEIGHT,E_LEVEL[level].WIDTH);
    m->setObject(p->getX(),p->getY(),p->getSymbol(),0); //set player on Map
    
    //Rock
    GameObject * rocks[E_LEVEL[level].ROCKS];
    for (int i = 0; i< E_LEVEL[level].ROCKS; i++){
        do{//Floor check
            x_temp = 1+rand()%(E_LEVEL[level].HEIGHT-2);
            y_temp = 1+rand()%(E_LEVEL[level].WIDTH-2);
        } while (m->getObject(x_temp, y_temp)!='.');

        rocks[i] = new Rock(x_temp,y_temp);
        m->setObject(rocks[i]->getX(), rocks[i]->getY(), rocks[i]->getSymbol(), i);
        
    }

    //Gem
    GameObject * gems[E_LEVEL[level].GEMS];
    for (int i = 0; i< E_LEVEL[level].GEMS; i++){
        do{//Floor check
            x_temp = 1+rand()%(E_LEVEL[level].HEIGHT-2);
            y_temp = 1+rand()%(E_LEVEL[level].WIDTH-2);
        } while (m->getObject(x_temp, y_temp)!='.');
        gems[i] = new Gem(x_temp,y_temp);
        m->setObject(gems[i]->getX(), gems[i]->getY(), gems[i]->getSymbol(), i);
       
    }
    
    //M_Apple
    GameObject * M_Apples[E_LEVEL[level].MAGICAPPLES];
    for (int i = 0; i< E_LEVEL[level].MAGICAPPLES; i++){
        do{//Floor check
            x_temp = 1+rand()%(E_LEVEL[level].HEIGHT-2);
            y_temp = 1+rand()%(E_LEVEL[level].WIDTH-2);
        } while (m->getObject(x_temp, y_temp)!='.');
        M_Apples[i] = new MagicApple(x_temp,y_temp);
        m->setObject(M_Apples[i]->getX(), M_Apples[i]->getY(), M_Apples[i]->getSymbol(), i);
        
    }

    //Monster
    GameObject * monsters[E_LEVEL[level].MONSTERS];
    for (int i = 0; i< E_LEVEL[level].MONSTERS; i++){
        do{//Floor check
            x_temp = 1+rand()%(E_LEVEL[level].HEIGHT-2);
            y_temp = 1+rand()%(E_LEVEL[level].WIDTH-2);
        } while (m->getObject(x_temp, y_temp)!='.');
        monsters[i] = new Monster(x_temp,y_temp);
        m->setObject(monsters[i]->getX(), monsters[i]->getY(), monsters[i]->getSymbol(), i);

    }

    do{
        std::cout<<"Level: "<<level+1<<"\nPlayer energy: ";
        showEnergy(energy);
        std::cout<<"\nPoints: "<<point<<"\n";
        m->print();
        if(energy < 0) endGame();
        std::cout<<"Please select action (move with wasd or q to escape)> ";
        std::cin>>opt;

        energy-=5;

        switch (opt)
        {
        case 'w':
            input = 1;
            break;
        case 'W':
            input = 1;
            break;
        case 'a':
            input = 2;
            break;
        case 'A':
            input = 2;
            break;
        case 's':
            input = 3;
            break;
        case 'S':
            input = 3;
            break;
        case 'd':
            input = 4;
            break;
        case 'D':
            input = 4;
            break;
        case 'q':
            endGame();
            break;
        case 'Q':
            endGame();
            break;
        default:
            energy+=5;
            std::cout<<"Wrong input.\nPress enter to continue!";
            std::cin.ignore();
            std::cin.get();
            break;
        }
        
        /* code */
        if (m->isWall(p->getX()+move_x[input],p->getY()+move_y[input])){
            //to player function
            std::cout<<"Hit the wall. Try Again. \nPress enter to continue!";
            std::cin.ignore();
            std::cin.get();
            energy+=5; //-> to player
        } else {
            m->clearObject(p->getX(),p->getY());
            p->setX(p->getX()+move_x[input]);//set new x
            p->setY(p->getY()+move_y[input]);//set new y
            if (m->getObject(p->getX(),p->getY())=='E') {
                finish = true;
            }
            if (m->isGem(p->getX(),p->getY())){
                E_LEVEL[level].GEMS--;
                point+=gems[m->getCode(p->getX(),p->getY())]->getValue();
            }
            if (m->isApple(p->getX(),p->getY())){
                energy = energy+M_Apples[m->getCode(p->getX(),p->getY())]->getValue();
            }
            if (m->isMonster(p->getX(),p->getY())){
                energy = energy-monsters[m->getCode(p->getX(),p->getY())]->getValue();
            }
            m->setObject(p->getX(),p->getY(),p->getSymbol(),0);
        }

        //
        if (energy>100) energy = 100; //no higher than 100

        if(E_LEVEL[level].GEMS==0&&nextLevel == false){
            nextLevel = true;
            //Exit
            do{//Floor check //tranfer to map class###########
                x_temp = 1+rand()%(E_LEVEL[level].HEIGHT-2);
                y_temp = 1+rand()%(E_LEVEL[level].WIDTH-2);
            } while (m->getObject(x_temp, y_temp)!='.');
            
            GameObject * exit = new Exit(x_temp,y_temp);
            m->setObject(exit->getX(), exit->getY(), exit->getSymbol(), 0);
        }

        if (system("CLS")) system("clear"); 
    }while(!finish);

    //FREE SPACE
    
    for (int i = 0; i < E_LEVEL[level].ROCKS; i++){
        delete [] rocks[i];
    }
    for (int i = 0; i < E_LEVEL[level].MONSTERS; i++){
        delete [] monsters[i];
    }
    for (int i = 0; i < E_LEVEL[level].MAGICAPPLES; i++){
        delete [] M_Apples[i];
    }
    for (int i = 0; i < E_LEVEL[level].GEMS; i++){
        delete [] gems[i];
    }
    delete p,m,exit,monsters,M_Apples,gems;
    if (level == MAX_LEVEL) {endGame();};
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