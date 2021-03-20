#include <iostream>
#include <vector>
int main(){
    //01
    std::cout<<"Ex 01"<<std::endl;
    std::vector<int> numbers; //Assign a vector
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    for (int i = 0; i < numbers.size(); i++){
        std::cout<<numbers[i]<<std::endl;
    }//output 2 3 4

    //02
    std::cout<<"Ex 02"<<std::endl;
    std::vector<int> numbers2(5);
    numbers2.at(0) = 7;
    numbers2.at(1) = 33;
    numbers2.push_back(2);
    numbers2.push_back(3);
    numbers2.push_back(5);
    for (int i = 0; i < numbers2.size(); i++){
        std::cout<<numbers2[i]<<std::endl;
    }//output 7 33 0 0 0 2 3 5 -> the size had change to 8

    //03
    std::cout<<"Ex 03"<<std::endl;
    std::vector<int>::iterator it;
    for(it=numbers.begin();it!=numbers.end();++it){
        std::cout<<*it<<std::endl;
    }
}