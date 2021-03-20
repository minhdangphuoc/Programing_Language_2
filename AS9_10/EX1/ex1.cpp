#include <iostream> 
//A09_1
double safeDiv(double a, double b) {
    if(b==0){
        throw std::runtime_error(std::string("Division by zero!")); 
    } else {
        return a/b;
    } 
}

int main(){
    std::cout<<safeDiv(10,0);
}