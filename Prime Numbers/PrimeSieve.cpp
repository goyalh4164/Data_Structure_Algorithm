#include<bits/stdc++.h>
using namespace std;
#define N 1000000
#define ll long long

void primeSieve(vector<int> & sieve){
    sieve[1]=sieve[0]=0;
    //start from 2 and mark all multiple of ith number(prime) as not prime
    for(ll i=2;i<=N;i++){
        if(sieve[i]){
            for(ll j=i*i;j<=N;j+=i){
                sieve[j]=0;
            }
        }
    }
}
int main()
{
    vector<int> sieve(N,1); //fill constructor
    primeSieve(sieve);
    for(int i=0;i<=100;i++){
        if(sieve[i]){
            cout<<i<<" ";
        }
    }
    return 0;
}