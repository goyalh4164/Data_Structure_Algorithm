#include<bits/stdc++.h>
using namespace std;
int NumberOfDigits(int n){
    if(n==0) return 0;
    return 1+NumberOfDigits(n/10);
}
int main()
{
    cout<<NumberOfDigits(121831);
    return 0;
}