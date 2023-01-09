#include <iostream>
using namespace std;

class ComplexNumbers
{
    // Complete this class
private:
    int real;
    int imag;

public:
    // Assigning Initial Value
    ComplexNumbers(int real, int imag)
    {
        this->real = real;
        this->imag = imag;
    }

    void print()
    {
        if (this->imag < 0)
        {
            cout << real << " " << imag << "i" << endl;
        }
        else
        {
            cout << real << " "
                 << "+"
                 << " "
                 << "i" << imag << endl;
        }
    }
    void plus(ComplexNumbers c2)
    {
        // It will Handle both the cases of part c and d
        this->real = this->real + c2.real;
        this->imag = this->imag + c2.imag;
    }
    void subtract(ComplexNumbers c2){
        // It will Handle both the cases of part c and d
        this->real=this->real - c2.real;
        this->imag=this->imag - c2.imag;
    }
};

int main()
{
    int real1, imaginary1;
    cout << "Enter the complex number :" << endl;
    cout << "Real Part :";
    cin >> real1;
    cout << "Imaginary Part" ;
    cin >> imaginary1;
    // Initialized the value of the complex number using constructor
    ComplexNumbers c1(real1, imaginary1);

    while (true)
    {
        cout<<"Press 1 to Print"<<endl;
        cout<<"Press 2 to add real part"<<endl;
        cout<<"Press 3 to add imag part"<<endl;
        cout<<"Press 4 to add new complex number"<<endl;
        cout<<"Press 5 to subtract real part"<<endl;
        cout<<"Press 6 to subtract imag part"<<endl;
        cout<<"Press 7 to subtract new complex number"<<endl;
        cout<<"Press 8 to exit"<<endl;
        int choice;
        cout<<"Enter Your Choice: ";
        cin>>choice;

        if (choice == 1)
        {
            c1.print();
        }
        else if (choice == 2)
        {
            int real_part;
            cout<<"Enter the real Part : ";
            cin>>real_part;
            ComplexNumbers c2(real_part,0);
            c1.plus(c2);
            c1.print();
        }
        else if (choice == 3)
        {
            int imag_part;
            cout<<"Enter the imag Part : ";
            cin>>imag_part;
            ComplexNumbers c2(0,imag_part);
            c1.plus(c2);
            c1.print();
        }
        else if (choice == 4)
        {
            int real_part;
            cout<<"Enter the real Part : ";
            cin>>real_part;
            int imag_part;
            cout<<"Enter the imag Part : ";
            cin>>imag_part;
            ComplexNumbers c2(real_part,imag_part);
            c1.plus(c2);
            c1.print();
        }
        else if (choice == 5)
        {
            int real_part;
            cout<<"Enter the real Part : ";
            cin>>real_part;
            ComplexNumbers c2(real_part,0);
            c1.subtract(c2);
            c1.print();
        }
        else if (choice == 6)
        {
            int imag_part;
            cout<<"Enter the imag Part : ";
            cin>>imag_part;
            ComplexNumbers c2(0,imag_part);
            c1.subtract(c2);
            c1.print();
        }
        else if(choice ==7){
            int real_part;
            cout<<"Enter the real Part : ";
            cin>>real_part;
            int imag_part;
            cout<<"Enter the imag Part : ";
            cin>>imag_part;
            ComplexNumbers c2(real_part,imag_part);
            c1.subtract(c2);
            c1.print();
        }
        else if(choice==8){
            break;
        }
        else{
            cout<<"Wrong Choice"<<endl;
        }

    }
    return 0;
}