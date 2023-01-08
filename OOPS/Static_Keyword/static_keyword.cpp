#include<bits/stdc++.h>
class Student{
    public:
    int rollNumber;
    int age;
    // these property shpould have same for all the student objects
    //Basically this property belongs to the class
    //By using static this property will belongs to the object 
    static int totalStudents;  //total number of students present
    //we want whenever we create student the total no. of students should increase by 1
    //static datamembers have no "this" keyword
    Student(){
        totalStudents++;
    }

    int getRollNumber(){
        return rollNumber;
    }
    //we want to access without any object as it is a class property so we need to make it static
    static int getTotalStudent(){
        //inside the static functions we can use only the static properties
        return totalStudents;
    }

};
//You can only initialize static properties outside the class

int Student :: totalStudents =0;  //initialize static data members

using namespace std;
int main()
{
    Student s0;
    cout<<s0.rollNumber<<" "<<s0.age<<endl;
    // how to print static data member of the class
    // cout<<s1.totalStudents<<endl;  //this works but it is invalid
    // s1.totalStudents=20;  //this line will change the property of the class it means it will reflect in all the objects

    Student s1;
    Student s2;
    Student s3;
    Student s4;
    Student s5;
    

    cout<<Student::totalStudents<<endl;
    cout<<Student::getTotalStudent()<<endl;

    return 0;
}