#include <iostream> 
//A09_3
double safeDiv(double a, double b) {
    if(b==0){
        throw std::runtime_error(std::string("Division by zero!")); 
    } else {
        return a/b;
    } 
}

int main(){
    int v = safeDiv(6.7, safeDiv(1,3));
    std::cout<<v;
    //It will access the safeDiv(1,3) at first and return 1/3 (Double).
    //After that, safeDiv(6.7,1/3 <- safeDiv(1,3)) will return value of 6.7/(1/3) = 20.1
    //This is nearly a recursion.
}