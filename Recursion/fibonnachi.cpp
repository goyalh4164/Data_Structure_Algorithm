#include<bits/stdc++.h>
using namespace std;
int fibonnachi(int n){
    if(n==0 || n==1) return n;
    return fibonnachi(n-1)+fibonnachi(n-2);
}
int main()
{
    cout<<fibonnachi(5);
    return 0;
}