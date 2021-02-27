#include <iostream>
#include <array>
#include <math.h>
#include <vector>

//Functions
bool div(float x, float y, int &result);
double sumArr(auto arr);
bool isDiagonalMatrix(auto arr);
double sumVector(auto vt);
void newOperator();

int main(){

    //EX1
    int value=6;
    
    std::cout<<div(5,1,value)<<" "<<value<<std::endl;
    
    //EX2
    std::array <double,4> arr = {2.2,10,5,11}; //Create new array with std::array
    
    std::cout<<sumArr(arr)<<std::endl;

    //EX3
    std::array <std::array<double, 5>,4> matrix = {{{1,0,0,0,0},
                                                    {0,1,0,0,0},
                                                    {0,0,1,0,0},
                                                    {0,0,0,1,0}}};
        
        //output
        std::cout<<((isDiagonalMatrix(matrix)==0)?("True"):("False"))<<std::endl;

    //EX4
    std::vector <double> vt; //Create a vector
    const int NUMBER_OF_VALUE = 5; //number of value

        //random seed 
        srand(time(0));
        
        for (int i = 1; i <= NUMBER_OF_VALUE; i++) 
            vt.push_back(rand()%100+1);

            //output
            std::cout<<sumVector(vt)<<std::endl;

    //EX5
    newOperator();
   

}

//EX1
bool div(float x, float y, int &result){
    
    if (y == 0)return 1;
    else {
        result=x/y;
        return 0;
    }
}

//EX2
double sumArr(auto arr){
    double sum = 0;
    
    for (int i = 0; i < arr.size(); i++){
        sum += arr[i];
    }
    return sum;
}

//EX3
bool isDiagonalMatrix(auto arr){
    
    //Check value at 
    for (int i=0; i < arr.size(); i++) {
		for (int j=0; j < arr[0].size(); j++) {
			if (i == j ) {
				if (arr[i][j] == 0) {
					return 1;
				}
			}
			else {
				if (arr[i][j] != 0) {
					return 1;
				}
			}
		}
	}
    return 0;
}

//EX4
double sumVector(auto vt){
    double sum_vt;
    //search value from begin to end and sum together
    for (auto value = vt.begin(); value != vt.end(); ++value){
        
        //print the values
        std::cout<<*value<<" ";
        
        //summary
        sum_vt+=*value;
    }
    return sum_vt;
}

//EX5
void newOperator(){
    int* arr; // dynamic array
    arr = new int[3]; // an array of 3 int elements

    //a loop, assigns the values 2, 4, and 8 to the array
    for (int i = 0;i<3;i++){
        arr[i] = pow(2,i+1);
    }
    
    for (int i =0;i<3;i++){
        std::cout<< arr[i]<< " ";
    }

    delete[] arr;
    std::cout<<"\nDelete Successfuly\n";
}