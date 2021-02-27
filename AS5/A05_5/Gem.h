class Gem
{
private:
    char* symbol; //Attribute
    int* value;  //Attribute
    static int objectCounter;
    static int deletedCounter;

public:
    
    
    void printSymbol();
    
    int getValue();

    void setValue(int);

    static int getObjectCount();

    static int getDeletedCount();

    // Constructor
    Gem(char, int);
    Gem(char);
    Gem(int);
    Gem();
    //Destructor
    ~Gem();
};

