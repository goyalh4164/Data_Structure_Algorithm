#include<bits/stdc++.h>
#include "student.h"
using namespace std;
int main()

{
    Student s1;  //constructor 1 called
    Student s2(101); //constructor 2 called
    Student s3(20,122); //constructor 3 called
    Student s4(s3); //Copy Constructor
    s1=s2;   //Copy Assignment operator
    //What will happen below;
    Student s5=s4;  //Copy Constructor  -->Because compiler will interpret it like Student s5(s4);
    
    return 0;
}