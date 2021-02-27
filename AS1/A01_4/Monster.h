class Monster
{
private:
    char symbol;
    int strength = 0;

public:
    int xPosition,yPosition;

    void printSymbol();

    void setValue(char inputSymbol, int inputX, int inputY);

    int getStrength();

    void setStrength(int);
};