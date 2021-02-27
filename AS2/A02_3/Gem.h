class Gem
{
private:
    char* symbol; //Attribute
    int* value;  //Attribute

public:
    void printSymbol();
    
    int getValue();

    // Constructor
    Gem(char symbol, int value);
    Gem(char symbol);

    //Destructor
    ~Gem();
};