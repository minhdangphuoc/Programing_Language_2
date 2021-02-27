#include <iostream>
#include "coin.h"

void CoinPurse::setQuantity(int quantity){
   this -> quantity = quantity;
}

int CoinPurse::getQuantity(){
    return quantity;
}

CoinPurse::CoinPurse(int addQuantity){
    quantity = addQuantity;
}