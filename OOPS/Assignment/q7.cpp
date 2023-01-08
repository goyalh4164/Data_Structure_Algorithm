#include<bits/stdc++.h>
using namespace std;

class baseClass1{
    public:
    int x,y;
    void getData(){
        cout<<"Enter first number: ";
        cin>>x;
        cout<<"Enter second data: ";
        cin>>y;
    }
};

class baseClass2{
    public:
    int a,b;
    void setData(){
        cout<<"Enter first number: ";
        cin>>a;
        cout<<"Enter second data: ";
        cin>>b;
    }
};

class Derived : public baseClass1 ,public baseClass2{
    public:
    void printSum(){
        int sum;
        sum=x+y;
        cout<<"Sum is :"<<sum<<endl;
    }
    void printProduct(){
        int product;
        product=a*b;
        cout<<"Product is: "<<product<<endl;
    }
};

int main()
{
    Derived obj;
    obj.getData();
    obj.printSum();
    obj.setData();
    obj.printProduct();

    return 0;
}