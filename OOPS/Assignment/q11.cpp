#include<bits/stdc++.h>
using namespace std;

double division(int a,int b){
    if(b==0){
        throw "Division by zero condition!";
    }
    return (a/b);
}

int main()
{
    int x;
    int y=0;
    double z=0;
    try
    {
        z=division(x,y);
        cut<<z<<endl;
    }
    catch(const char * msg){
        //cerr means character error
        cerr<<msg<<endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}