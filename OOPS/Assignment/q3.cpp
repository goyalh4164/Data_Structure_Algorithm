#include <iostream>
#include <math.h>
using namespace std;


int power(int a, int b)
{
    int i=min(a,b);
    int j=max(a,b);
    for(int k=0;k<i;k++){
        j=j*j;
    }
    return j;
}
//overloaded power function differentiated by the return type
double power(double a, double b)
{
    //using inbuilt power function for the double power overloaded function
	double result=pow(a,b);
    return result;
}

// Driver code
int main()
{
    cout<<"when you are using both integral values"<<endl;
	cout<<"Calling Intergral Power Function: "<<power(10, 2)<<endl;
    cout<<"Calling double Power Function: "<<power(5.3, 6.2)<<endl;
    return 0;
}
