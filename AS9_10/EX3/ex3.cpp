//A09_4
#include <iostream>
template<class T>
class MyStack{
    private: 
    int * stack, size;
    int n;
    public:
    MyStack(int size){
        stack = new int[size];
        this -> size = size;
        n = 0;
    }
    void push(T item){
        if (isFull()){
            throw std::runtime_error(std::string("Stack is full!")); 
        } else {
            stack[n] = item;
            n++;
        }
    }
    T pop(){
        int output;
        if (isEmpty()){
            throw std::runtime_error(std::string("Stack is Empty!"));
        } else {
            n--;
            return stack[n];
        }
    }
    T peek(){
        if (isEmpty()){
            throw std::runtime_error(std::string("Stack is Empty!"));
        } else {
            return stack[n-1];
        }
    }
    bool isEmpty(){
        if (n == 0) {
            return true;
        }
        return false;
    }
    bool isFull(){
        if (this -> n == this -> size-1){
            return true; 
        }
        return false;
    }
    int getMaxCapacity(){
        return size;
    }
    int getNumberOfItems(){
        return n;
    }


};

int main(){
    MyStack<int> s(5);  // Creates an empty stack of ints, with the capacity of 5 items.
    s.push(3);  // Adds 3 to the stack.
    s.push(7);  // Adds 7 to the stack.
    std::cout << s.pop() << std::endl;  // Prints 7. Now only 3 in the stack
    std::cout << s.peek() << std::endl;  // Prints 3. Now only 3 in the stack
    std::cout << s.pop() << std::endl;  // Prints 3. The stack is now empty.
    std::cout << s.getNumberOfItems() << std::endl;  // Prints 0 since the stack is empty.
}