class Position
{
private:
    /* data */
     int x, y;
public:

    void set(int,int);
    void setX(int);
    void setY(int);
    int getX();
    int getY();
    bool equals(Position player);
    friend bool operator == (const Position &,const Position &);
};

