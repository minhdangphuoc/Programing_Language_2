#include <iostream>
#include <math.h>

class DistanceCalculator{
    public:
    virtual bool isZero(int a[], int len) = 0;
    virtual double distance(int a[], int b[], int len) = 0;
};

class ManhattanDistanceCalculator: public DistanceCalculator{
    public:
    bool isZero(int a[], int len) override {
        for (int i = 0; i<len; i++){
            if (a[i]!=0) {return false;}
        }
        return true;
    }
    virtual double distance(int a[], int b[], int len) override {
        std::cout<<"\nManhattanDistanceCalculator::distance Access\n";
        double dis = 0;
        for (int i = 0; i<len; i++){
            dis += abs(a[i]-b[i]);
        }
        return dis;
    }
};

class EuclideanDistanceCalculator: public DistanceCalculator{
    public:
    bool isZero(int a[], int len) override {
        for (int i = 0; i<len; i++){
            if (a[i]!=0) {return false;}
        }
        return true;
    }
    virtual double distance(int a[], int b[], int len) override {
        std::cout<<"\nEuclideanDistanceCalculator::distance Access\n";
        double dis = 0;
        for (int i = 0; i<len; i++){
            dis += pow(a[i]-b[i],2);
        }
        return sqrt(dis);
    }
};

int main(){
    const int len = 4;
    int a[len]{1,1,3,2},b[len]{2,2,-3,5};
    ManhattanDistanceCalculator mCal;
    EuclideanDistanceCalculator eCal;
    DistanceCalculator * cal {&mCal};
    
    std::cout<<cal->distance(a,b,len)<<std::endl;
    cal = &eCal; //change to eCal
    std::cout<<cal->distance(a,b,len)<<std::endl;
}