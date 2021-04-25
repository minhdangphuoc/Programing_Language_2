#include<iostream>

int main() {
    char c;
   // Set the terminal to raw mode
    while(1) {
        system("stty raw");
        c = getchar(); 
        // terminate when "." is pressed
        system("stty cooked");
        system("clear");
        std::cout << c << " was pressed."<< std::endl;
        if(c == '.') {
            system("stty cooked");
            exit(0);
        }  
    }
}
