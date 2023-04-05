#include<bits/stdc++.h>
using namespace std;

//Brute Force
void factorise(int n){
    for(int i=2;i<=n;i++){
        if(n%i==0){
            int count=0;
            while(n%i==0){
                n/=i;
                count++;
            }
            cout<<i<<"^"<<count<<",";
        }
    }
}
//optimized approach
// Obs : Once N is reduced to a prime number ,the 
// only factor of that number will be the number itself

// if a number doesn't have any factor till sqrt(n)
// then it is a prime number
void factoriseOpt(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int count=0;
            while(n%i==0){
                n/=i;
                count++;
            }
            cout<<i<<"^"<<count<<",";
        }
    }
    if(n!=1) cout<<n<<"^"<<"1"<<endl;
}
int main()
{
    int n;
    cin>>n;
    factoriseOpt(n);
    return 0;
}