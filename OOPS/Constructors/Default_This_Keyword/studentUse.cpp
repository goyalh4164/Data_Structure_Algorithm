#include<bits/stdc++.h>
#include "student.h"
// WHENEVER YOU CREATE YOUR OWN CONSTRUCTOR NO MATTER PARAMERITIZED OR SIMPLE INBUILT CONSTRUCTOR DIES AUTOMATICALLY
using namespace std;
int main()
{
    Student s1; //when we write this it calls the default constructor s1.Student();
    /*Default constructor looks like 
    Constructor is called only once in lifetime of object
    Student(){
    
    }
    */
   s1.display();

   //Calling constructor 2 
   Student s3(10);
   s3.display();

   Student * s4=new Student(7);
   s4->display();
   
   //Calling constructor 3

   Student * s5=new Student(1,2);
   s5->display();

   //"this" keyword testing
   Student * s6=new Student(10,20);
   cout<<s6<<endl;
   //we have received the same address in both lines
   

    
    return 0;
}