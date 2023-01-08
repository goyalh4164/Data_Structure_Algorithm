#include<bits/stdc++.h>
using namespace std;
class A{
    public:
    int x;
};
class B :public A{
    public:
    B(){
        cout<<"Enter first num: ";
        cin>>x;
    }
};
class C{
    public:
    int y;
    C(){
        cout<<"Enter the Second num:";
        cin>>y;
    }
};
class D :public B,public C{
    public:
    void Product(){
        cout<<"Product : "<<x*y<<endl;
    }
};
int main()
{
    D obj;
    obj.Product();
    return 0;
}