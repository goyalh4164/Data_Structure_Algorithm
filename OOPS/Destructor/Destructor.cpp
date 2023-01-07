#include<bits/stdc++.h>
#include "student.h"
using namespace std;
int main()
{
    //WHENEVER YOU CREATE YOUR DESTRUCTOR INBUILT DESTRUCTOR DIES
    Student s1(10,1001);
    Student s2(20,201);
    Student * s3=new Student(12,313);
    //Destructor is called when the scope of object memory seems to be finishing for dynamic objects you have to delete memory by yourself
    delete s3;  //this line will call the destructor
    

    return 0;
}