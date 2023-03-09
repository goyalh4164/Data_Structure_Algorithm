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
void updateIthBit(int &n,int i,int v){
    clearIthBit(n,i); //First clear the position where the new bit is going to be set
    int mask=(v<<i);  // if v is 1 then Ith bit becomes 1 else 0
    n=n|mask;
}
void clearLastBits(int &n,int i){
    int mask=~0;
    mask=mask<<i;
    n=n&mask;
}
int main()
{
    // int x=5;
    // cout<<getIthBit(5,0)<<endl;
    // int n=7;
    // clearIthBit(n,2);
    // cout<<n<<endl;
    // int y=5;
    // setIthBit(y,1);
    // cout<<y<<endl;
    int x=15;
    clearLastBits(x,2);
    cout<<x;
    return 0;
}