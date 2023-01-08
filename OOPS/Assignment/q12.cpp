#include<bits/stdc++.h>
#include<vector>
using namespace std;
class Student{
    public:
    int age;
    int rollNumber;
    Student(int age,int rollNumber){
        this->age=age;
        this->rollNumber=rollNumber;
    }
};
void print(vector<Student> & v){
     cout<<"  rollNumber  "<<"  "<<"  age  "<<endl;
    for(auto i : v){
        cout<<"      "<<i.rollNumber<<"  "<<"       "<<"  "<<i.age<<"  "<<endl;
    }
}

bool compare(Student s1,Student s2){
    //sorting on the basis of the rollNumber
    return s1.rollNumber<s2.rollNumber;
}
int main()
{
    //Using Vector
    vector<Student> v;
    //inserting data into the vector
    v.push_back(Student(5,4));
    v.push_back(Student(7,1));
    v.push_back(Student(1,3));
    v.push_back(Student(4,2));
    v.push_back(Student(3,5));
    //printing the vector before using sorting
    cout<<"printing the vector before using sorting"<<endl;
    print(v);
    //we are using sort function with a bool compare function to guide
    // on thich basis objects will going to be sorted
    cout<<"printing the vector after using sorting"<<endl;
    sort(v.begin(),v.end(),compare);
    print(v);
    cout<<"You can see the vector is sorted now on the basis of the rollNumber"<<endl;

    return 0;
}