class Point
{
private:
    /* data */
    int x,y;
public:
    int getX() {return x;}
    int getY() {return y;}

    Point(int x, int y){
        this -> x = x;
        this -> y = y;
    }
};

class Circle : public Point
{
private:
    /* data */
    int r;
public:
    int getR(){return r;}
    Circle(int x, int y, int r):Point(x,y){ 
        this -> r = r;
    }   
};

class Rectangle
{
private:
    /* data */
    int width, height;
public:
    Point* point,* point2;
    
    /*Rectangle(int x, int y, int width, int height){
    point = new Point(x,y);
    
    this -> width = width;
    this -> height = height;
    }*/

    Rectangle(int x1, int y1, int x2, int y2){
        point = new Point(x1,y1);
        point2 = new Point(x2,y2);
    }

    /*void print (){
        std::cout << "\nx: " << point -> getX() << " y: " << point -> getY() << " w: " << width << " h: " << height << "\n";
    }*/

    void print (){
        std::cout << "\nx1: " << point -> getX() << " y1: " << point -> getY() << " x2: " << point2 -> getX() << " y2: " << point2 -> getY() << "\n";
    }
};

class Object{
    private:
        int value;
    public:

    Object(int value){
        this -> value = value;
    }

    Object(){
        value = 100;
    }

};