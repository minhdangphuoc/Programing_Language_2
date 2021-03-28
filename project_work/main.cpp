#include <iostream>
#include "lib/Map.h"
#include "lib/Constants.h"

const int MAX_LEVEL=10;

struct {
    int MAPSIZEX, MAPSIZEY, MONSTERS, GEMS, MAGICAPPLES, ROCKS;
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
    for(int i=0; i<=MAX_LEVEL; i++){
        
    }
}

void gameLoop(const int level){
    
    Player * p = new Player(%E_LEVEL[level-1].MAPSIZEX);

    gameLoop(level+1);
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
        gameLoop(1);
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

    OS_select();  
}