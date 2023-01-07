using namespace std;
class Student{
    private:
    int age;
    public:
    
    //Default Constructor
    //when we write it in-built constructor dies
    Student (){
        cout<<"Constructor called"<<endl;
    }

    //Parameritized Constructor
    Student(int r){
        cout<<"Parameritized Constructor called"<<endl;
        rollNumber=r;
    }

    //One more constructor
    Student(int rollNumber,int age){
        cout<<"Parameritized Constructor two called"<<endl;
        //"this" keyword holds the address of the current object
        //this keyword points to the current object from which the constructor is called
        cout<<"Address of the object for which the constructor is called :"<<(this)<<endl;
        this->rollNumber=rollNumber;
        this->age=age;
    }



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