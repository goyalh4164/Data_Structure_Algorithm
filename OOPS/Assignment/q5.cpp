#include<bits/stdc++.h>
#include <string>
using namespace std;
class Student{
    public:
    int age;
    int rollNumber;
    //No-Argument Constructor it is used for filling garbage value
    Student(){
        cout<<"I am No Argument Constructor"<<endl;
    }
    //One-argument constructor
    Student(int age){
        cout<<"I am One Argument Constructor Setting age of the student object"<<endl;
        this->age=age;
    }
    //Two-argument constructor
    Student(int age,int rollNumber){
        cout<<"I am Two Argument Constructor Setting age and roll Number of the student object"<<endl;
        this->age=age;
        this->rollNumber=rollNumber;
    }
    //Copy Constructor
    Student(Student const & s){
        cout<<"I am Copy Constructor"<<endl;
        this->age=s.age;
        this->rollNumber=s.rollNumber;
    }
    Student(string msg){
        cout<<"I am Dynamic Constructor"<<endl;
        cout<<"You Message :";
        string * temp=new string; //dynamic memory allocation
        *(temp)=msg;
        cout<<msg<<endl;
    }

};
int main()
{
    Student s1; //No-Argument Constructor
    cout<<endl;
    Student s2(10); //One-Argument Constructor
    cout<<endl;
    Student s3(10,20); //Two-Argument Constructor
    cout<<endl;
    Student s4(s3);  //Copy Constructor
    cout<<endl;
    string arr="Using this Program";
    Student s5(arr);  //Dynamic constructor
    return 0;
}