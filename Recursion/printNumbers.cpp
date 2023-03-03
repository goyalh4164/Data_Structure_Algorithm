#include<bits/stdc++.h>
using namespace std;
void printNumbers(int n){
    if(n==0) return;
    printNumbers(n-1);
    cout<<n<<endl;;

}
int main()
{
    printNumbers(11);
    return 0;
}