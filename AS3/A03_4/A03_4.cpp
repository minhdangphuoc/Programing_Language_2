#include <iostream>
#include "coin.h"

int removeCoins(CoinPurse &purse, int removeQuantity);

int main(){
    CoinPurse purse(10);  // A sample coin purse with 10 coins.
    int removed = removeCoins(purse, 11);  // Remove 3 coins from the purse.

    std::cout<<"Remove "<<removed<<" coins"<<", quantity: "<<purse.getQuantity();
}

int removeCoins(CoinPurse &purse, int removeQuantity){
    if (purse.getQuantity()>=removeQuantity){
        purse.setQuantity(purse.getQuantity() - removeQuantity);
        return removeQuantity;
    }else return 0; 
}