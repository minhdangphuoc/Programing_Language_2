#include <iostream>
#include "coin.h"

int removeCoins(CoinPurse* const p, int removeQuantity);

int main(){
    //01
        CoinPurse purse(10);  // A sample coin purse with 10 coins.
        int removed = removeCoins(&purse, 3);  // Remove 3 coins from the purse.

        std::cout<<"\nEX1: "<<removed<<" "<<purse.getQuantity()<<std::endl;

    //02
        //create dynamic integer and assign to 1
        int* num_in = nullptr;
        num_in = new int;
        *num_in = 1;
        //before delete
        std::cout<<"\nEX2:\nBefore: "<<*num_in<<std::endl;
        delete num_in;
        //after delete
        std::cout<<"After: "<<*num_in<<std::endl;

    //03
        //create dynamic double and assign to 18.5
        double* num_do;
        num_do = new double {18.5};//or *num_do = 18.5;
            
        //output
        std::cout<<"\nEX3:\n"<<*num_do<<std::endl;//assigned value
        std::cout<<&num_do<<std::endl;//address
        std::cout<<sizeof(num_do)<<std::endl;//size of a double variable
        std::cout<<sizeof(*num_do)<<std::endl;//size of the pointer variable
        delete num_do;

        //explain
        std::cout<<"////////////////////////"<<std::endl;//
        std::cout<<sizeof(double)<<std::endl;//size of a double variable
        std::cout<<sizeof(int)<<std::endl;//size of a int variable
        std::cout<<sizeof(char)<<std::endl;//size of a char variable
        std::cout<<"As you can see clearly, the output will be diffrent and there are the size of variable in byte. In most of computer, 1 byte equal to 8 bit. So if you multiply with the outputs, you will find out the range of each types of variable\nEx: integer have 4 bytes, so the range of integer is 2^(8*4) from -2147483648 to 2147483647\n"<<std::endl;
    
    //04
        //Dynamically allocate an array of five ints
        int* arr;
        arr = new int[5] {1,2,3,4,5};
        
        //print
        std::cout<<"\nEX4: \n";
        for (int i = 0; i < 5; i++)std::cout<<(arr[i])<<std::endl;
        
        //delete
        delete [] arr;
        std::cout<<"Deleted\n";

        //print again
        for (int i = 0; i < 5; i++)std::cout<<(arr[i])<<std::endl;
    
    //05
        //create a pointer and an array
        int vals[]={4,7,11}, *valptr;
        valptr = vals;
        
        //print
        std::cout<<"\nEX5: \n";
        for (int i = 0; i<3; i++) std::cout<<*(valptr+i)<<std::endl;
}

int removeCoins(CoinPurse* const p, int removeQuantity){
    //replace . to ->
    p->setQuantity(p->getQuantity() - removeQuantity);
    return removeQuantity; 
}