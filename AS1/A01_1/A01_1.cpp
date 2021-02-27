#include <iostream>
#include <string.h>
#include <stdlib.h>

const std::string legalInput = {"wasdWASD"};

void process(){
    int i;
    char input;
    
    //
    std::cout<<"Please enter movement (wasd) or Q to escape > ";
    std::cin>>input;
    
    //
    if (input == 'q'||input == 'Q'){
            std::cout<<"Finished. \n";
            system("exit");
            exit(0);
    }
    
    //
    for (i = 0;i<8;i++){
        
        
        if (input == legalInput[i]){
            std::cout<<"Processing input: "<<legalInput[i]<<std::endl;
            break;
        }

    }

    if (input != legalInput[i]){
        std::cout<<"Unknown input: "<<input; 
    }

}

void gameLoop(){
    //
    process();
}

int main(){
    while(1)gameLoop();
}