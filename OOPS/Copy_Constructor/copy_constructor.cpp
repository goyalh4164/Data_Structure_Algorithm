#include<bits/stdc++.h>
#include <string>
using namespace std;
// ---------------------------------------------------------------------------------------------------
class Student{
    public:
    int age;
    char * name;
    Student(int age,char * name){
        this->age=age;
        // this->name=name;  //Shallow Copy

        // Deep Copy
        //Create a new array to store the name
        this->name=new char[strlen(name)+1]; //this 1 is for the null character //Now this->name is pointing to some other memory
        strcpy(this->name,name);   //copying it character by character
    }

    //Creating Copy Constructor

    Student(Student const &s){  //here it will call itself so we use refrences and to avoid that this constructor to change the value of the passed object we will use "const keyword" so that it can only read the value of s not change it
        this->age=s.age;
        // this->name=s.name; //Shallow Copy

        //Deep Copy
        this->name=new char[strlen(s.name)+1];
        strcpy(this->name,s.name);

    }
    void display(){
        cout<<name<<" "<<age<<" "<<endl;
    }
};
// ---------------------------------------------------------------------------------------------------
int main()
{
    char name[]="abcd";
    Student s1(20,name);
    s1.display(); 
    
    Student s2(s1);

    s2.name[0]='x';
    s1.display();  //xbcd ? Because inbuilt copy constructor does the shallow copy  
    //Now solved by our own copy constructor
    s2.display();  //xbcd
    

    return 0;
}