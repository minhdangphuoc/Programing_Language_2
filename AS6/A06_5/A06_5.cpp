#include <iostream>
#include "class.h"

int add(int x, int y){
    return x+ y;
}

std::string add(std::string x, std::string y){
    return x+ y;
}

int main(){
    //A06_1
    Circle c1(2,3,5);

    std::cout << c1.getX() << " " << c1.getY() << " " << c1.getR();

    //A06_2
    //A06_2_a re1(x,y,width,height)
    //Rectangle re1(3,5,5,5); 
    
    //A06_2_b re1(x1,y1,x2,y2)
    Rectangle re1(2,3,5,3);
    re1.print();

    //A06_3
    /*
    1/ Difference of [is-a]/inheritance and [has-a]/composition
    1. "[is-a]/inheritance" is the relationship between base and derived like father and son. 
        For Example: 
        - Class Dad has 2 private variables: Name (string) and age (int), 2 public variables: goodAtMath (bool) = False and handsome (bool) = True
        - Class Son also has 2 private variables: Name (string) and age (int), 2 public variables: goodAtCode (bool) = True
        Benefit:
        * The Son could get the "goodAtMath = False" or "Handsome = True" from the Dad.
        Drawbacks:
        * However, The Dad could not get "goodAtCode = True" from the Son.
        * The Son could not get the name and the age from the Dad, because those are private value.
        * The Dad could not get the name and the age from the Son, because those are private value.
    2.  "[Has-a]/composition" is the more equal relationship from 2 classes
        For Example:
        - Company_1 (Class) created a prototype Toy_1 (private member) and 2 members: makeToy(void)(public) and income(int)(private).
        - Company_2 (Class) want to buy and re-sell toys on their supermarket. - Company_2 = [is-a]/inheritance
        Benefit:
        * Company_2 could only request Company_1 directly to makeToy 
        Drawback:
        * Limited access to Company_1's private members
        
        - After some years, Company_2 decided to buy all Company_1 and change the Company_1's name to (Company_1 Company_Toy). - Company_2 = [has-a]/composition
        Benefits:
        * Company_2 now can access the income and the prototype (private member) by calling Company_Toy
    */

   //A06_4
    int iVal = add(3,5);
    std::string sVal = add("cat","fish");
    std::cout<< iVal <<" "<< sVal << std::endl;

    //A06_5 
    Object o1(100); 
    Object *o2 = new Object(200); 
    delete o2;
    Object o3 = Object(300);
}