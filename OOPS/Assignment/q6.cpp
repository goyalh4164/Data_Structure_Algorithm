#include<bits/stdc++.h>
using namespace std;
class baseClass{
    public:
    int x;
    void getDataOne(){
        cout<<"Enter first number: ";
        cin>>x;
    }
};
class Derived1 : public baseClass{
    public:
    int y;
    void getDataTwo(){
        cout<<"Enter second number: ";
        cin>>y;
    }
};
class Derived2 : public Derived1{
    public:
    int z;
    void getDataThree(){
        cout<<"Enter third number: ";
        cin>>z;
    }
};
class Derived3 : public Derived2{
    public:
    int add;
    void printSum(){
        cout<<"The Sum of the three numbers :"<<x+y+z<<endl;
    }
};

int main()
{
    Derived3 obj;
    obj.getDataOne();
    obj.getDataTwo();
    obj.getDataThree();
    obj.printSum();
    return 0;
}