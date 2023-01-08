#include<bits/stdc++.h>
using namespace std;
class Student{
    public:
    int age;
    const int rollNumber;  //we want that rollNumber should not change once initialized
    int &x;
    //so to remove garbage problem we can use constructor...this will also not work because at the time of decalaration garbage is assigned already to it
    // Student (int r){
    //     this->rollNumber=r;  //NOT A WAY
    // }

    //we have to take the help of initialization list

    //Syntax
    // Student(int r) : rollNumber(r){} //it works just like constructor
    //why it is working properly??
    //Because when we initialize constructor the rollNumber value is assigned to r during the creation of the memory
    //multiple nitialization list argument
    // Student(int r,int age) : rollNumber(r) ,age(age){}  //there is no need to use this keyword if they have same variable name also
    //we need initilazation list in refrence variables also
    //here we have to use this keyword as we are using the object age memory not the argument
    //we can make only one initilization list only
    Student(int r,int age):rollNumber(r),age(age),x(this->age){}



};
int main()
{
    /*int a=5;  //similar to 
    // int a;
    // a=5;
    //we can do this But
    //int const b=5;
    // this can't be done 
    // int const b;
    // b=5
    //we need to provide the value at the time of initialization only
    //similarly with this
    //int i=5;
    //int & j=i;  //ok
    /*
    But not this int & j;
    j=i;
    //Pasted an image for more info
    */
    Student s1(101,3);  //error comes here because when we creaating the const variable then we have to initialize it when it is declayerd but default constructor will initialize if it with garbage which is a problem
    s1.age=20;
    
    return 0;
}