class Gem
{
private:
    char* symbol; //Attribute
    int* value;  //Attribute
    static int objectCounter;

public:
    void printSymbol();
    
    int getValue();

    static int getObjectCount();

    // Constructor
    Gem(char symbol, int value);
    Gem(char symbol);

    //Destructor
    ~Gem();
};

