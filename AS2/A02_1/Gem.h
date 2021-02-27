class Gem
{
private:
    char symbol; //Attribute
    int value;  //Attribute

public:
    void printSymbol();
    
    int getValue();

    // Constructor
    Gem(char inputSymbol, int inputValue);
    Gem(char inputSymbol);
};