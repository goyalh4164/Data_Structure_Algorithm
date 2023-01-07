#include<bits/stdc++.h>
#include "student.h"
using namespace std;
int main()
{
    Student s1(100,1001);
    cout<<"S1 : ";
    s1.display();
    //copy constructor
    Student s2(s1);
    cout<<"S2 ";
    s2.display();

    Student * s3=new Student(20,2001);
    cout<<"s3 ";
    s3->display();
    Student s4(*s3);
    cout<<"s4 ";
    s4.display();
    Student * s5=new Student(s4);
    cout<<"s5 ";
    s5->display();
    Student * s6=new Student(*s3);
    cout<<"s6 ";
    s6->display();
    //copy assignment operator(=)
    //Since we know that copy constructor can be called only once for the object so if we need to copy of the pre-existing objects then we can use copy assignment operator
    Student s7(20,1212);
    Student s8(2,11);
    Student * s9=new Student(10,3001);
    s8=s7;
    *s9=s7;
    s9->display();





    return 0;
}