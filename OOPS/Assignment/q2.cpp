#include<bits/stdc++.h>
using namespace std;
float simple_Interest(float Principal,int time,float rate=12.0){
    return (Principal*time*rate)/100;
}
int main()
{
    //when passing all the arguments
    cout<<"Simple Interest = "<<simple_Interest(10000,5,15)<<endl;
    //when passing only principal amount and time
    
    cout<<"Simple Interest = "<<simple_Interest(10000,3)<<endl;
    return 0;
}