using namespace std;
class Student{
    private:
    int age;
    public:
    int rollNumber;
    //private properties can be accesed within the class
    //display function
    void display(){
        cout<<age<<" "<<rollNumber<<endl;
    }
    //get age-->getter
    int getAge(){
        return age;
    }
    //setAge-->setter
    void setAge(int a){
        //we can put a check here if a is less than 0 then throw error
        //you can ask for password before editing it
        //it is basically a interface between class variable and user
        age=a;
    }


};