#include<bits/stdc++.h>
#include "student.h"

using namespace std;
int main()
{
    //Create objects statically
    Student s1;
    Student s2;
    Student s3,s4,s5;

    //Setting data of static objects
    s1.setAge(24);
    s1.rollNumber=101;

    s1.display();
    //Create objects dynamically
    Student * s6=new Student;
    //Setting data of static objects
    s6->setAge(19);
     // or
    s6->rollNumber=34;
    //Printing it
    //using display function
    s6->display();
    
    return 0;
}