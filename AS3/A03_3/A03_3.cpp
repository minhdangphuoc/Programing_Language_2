#include <iostream>

void swap(int *x, int *y);

int main(){
    //variable
    int num1 = 100, num2 = 200;

    //run function
    swap(&num1,&num2);

    //test the output
    std::cout<<num1<<" "<<num2;

}

//swap function
void swap(int *x, int *y){
    //swap algorithm without third variable
    *x+=*y;  //ex: x = x+y = 31 , x = 31 , y = 16
    *y=*x-*y; //ex: y = x-y = 15 , x = 31 , y = 15
    *x-=*y;  //ex: x = x-y = 16 , x = 16 , y = 15
}