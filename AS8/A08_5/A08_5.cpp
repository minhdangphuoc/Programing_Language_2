#include <iostream>
#include <math.h>
//A08_5_1
class DistanceCalculator{
    public:
    virtual bool isZero(int a[], int len) final {
        bool check;
        for (int i = 0; i<len; i++){
            if(a[i]!=0){
                return false;
            }
        }
        return true;
    }
    virtual double distance(int a[], int b[], int len){
        std::cout<<"\nDistanceCalculator::distance Access\n";
        double dis = 0;
        for (int i = 0; i<len; i++){
            dis += pow(a[i]-b[i],2);
        }
        return sqrt(dis);
    }
};
//A08_5_2
class ManhattanDistanceCalculator: public DistanceCalculator{
    public:
    //final make this function no longer overridable
    //bool isZero(int a[], int len) override {} //Don't Work
    virtual double distance(int a[], int b[], int len) override {
        std::cout<<"\nManhattanDistanceCalculator::distance Access\n";
        double dis = 0;
        for (int i = 0; i<len; i++){
            dis += abs(a[i]-b[i]);
        }
        return dis;
    }
};

class ChangedMyMindDistanceCalculator:public ManhattanDistanceCalculator{
    public:
    virtual double distance(int a[], int b[], int len) override {
        return 0;
    }
};

int main(){
    //A08_5_1
    DistanceCalculator cal;
    const int len = 4;
    int a[len]{1,1,3,2},b[len]{2,2,-3,5};

    if (!cal.isZero(a,len)&&!cal.isZero(b,len)){
        std::cout<<cal.distance(a,b,len)<<std::endl;
    }

    //A08_5_2
    ManhattanDistanceCalculator mCal;
    DistanceCalculator * cal2 {&mCal};

    if (!cal2->isZero(a,len)&&!cal2->isZero(b,len)){
        std::cout<<cal2->distance(a,b,len)<<std::endl;
    }

    ChangedMyMindDistanceCalculator cCal;
    ManhattanDistanceCalculator * mCal2 {&cCal};

    if (!mCal2->isZero(a,len)&&!mCal2->isZero(b,len)){
        std::cout<<mCal2->distance(a,b,len)<<std::endl;
    }
}