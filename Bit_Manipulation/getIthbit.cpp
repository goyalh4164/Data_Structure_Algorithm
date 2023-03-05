#include<bits/stdc++.h>
using namespace std;
int getIthBit(int n,int i){
    int mask=(1<<i);
    return (n&mask)>0 ? 1 : 0;
}
void clearIthBit(int &n,int i){
    int mask=~(1<<i);
    n=n&mask;
}
void setIthBit(int &n,int i){
    int mask=(1<<i);
    n=(n|mask);
    
}
int main()
{
    int x=5;
    cout<<getIthBit(5,0)<<endl;
    int n=7;
    clearIthBit(n,2);
    cout<<n<<endl;
    int y=5;
    setIthBit(y,1);
    cout<<y<<endl;

    return 0;
}