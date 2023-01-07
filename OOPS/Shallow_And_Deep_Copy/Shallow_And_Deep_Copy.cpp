#include<bits/stdc++.h>
#include <string>
using namespace std;
// ---------------------------------------------------------------------------------------------------
class Student{
    int age;
    char * name;
    public:
    Student(int age,char * name){
        this->age=age;
        // this->name=name;  //Shallow Copy

        // Deep Copy
        //Create a new array to store the name
        this->name=new char[strlen(name)+1]; //this 1 is for the null character //Now this->name is pointing to some other memory
        strcpy(this->name,name);   //copying it character by character
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
    s1.display();  //working ok

    name[3]='e';
    Student s2(24,name); //working ok
    s2.display();
    s1.display(); //here name is abce this is because we have changed the name in the main but the char is pointing to the same name in the main so any changes affect both the objects. This is known as Shallow copy
    //Now the above issue is solved by using the deep copy
    return 0;
}