#include<iostream>  
using namespace std;    
void swap_call_by_value(int x,int y){
    int temp;
    temp=x;
    x=y;
    y=x;
}
void swap_call_by_refrence(int &x, int &y)  
{  
 int temp;  
 temp=x;  
 x=y;  
 y=temp;  
}  
int main()   
{    
 int x=500, y=100;    
 swap_call_by_value(x, y);  // passing value to function 
 cout<<"Real Values of x and y: "<<x<<" "<<y<<endl;
 cout<<"values after using call by value swap function: ";
 cout<<x<<" "<<y<<"--> No change"<<endl;
 swap_call_by_refrence(x,y);
 cout<<"values after using call by refrence swap function: ";
 cout<<x<<" "<<y<<"--> Values Swaped"<<endl;
 
 return 0;  
}    