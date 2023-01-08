#include<bits/stdc++.h>
using namespace std;
class B{
    public:
    virtual void who(){
        cout<<"Base Class"<<endl;
    }
};
class D1 :public B{
    public:
    void who(){
        cout<<"First Derivation"<<endl;
    }
};
class D2 :public B{
    public:
    void who(){
        cout<<"Second Derivation"<<endl;
    }
};
int main()
{
    B base_obj;
    B *ptr;
    D1 D1_obj;
    D2 D2_obj;

    ptr=&base_obj;
    ptr->who();

    ptr=&D1_obj;
    ptr->who();

    ptr=&D2_obj;
    ptr->who();
    return 0;
}