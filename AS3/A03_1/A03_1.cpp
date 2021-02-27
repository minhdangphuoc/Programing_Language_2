#include <iostream>

int main(){
    //variable
    int x = 15;
    int* iPtr = &x;

    //assign *iPtr with 16
    *iPtr = 16;    
    
    //Test value x
    std::cout<<x;
}