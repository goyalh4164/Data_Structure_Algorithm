#include<iostream>
#include<algorithm>
using namespace std;
class Fraction{
    private:
    int numerator;
    int denominator;

    public:
    Fraction(int numerator,int denominator){
        this->numerator=numerator;
        this->denominator=denominator;
    }
    void print(){
        cout<<this->numerator<<" / "<<denominator<<endl;
    }
    void simplify(){
        int gcd=1;
        int j=min(this->numerator,this->denominator);
        for(int i=1;i<=j;i++){
            if(this->numerator % i == 0 && this->denominator %i ==0){
                gcd=i;
            }
        }
        this->numerator=this->numerator/gcd;
        this->denominator=this->denominator/gcd;
    }
    // void add(Fraction const & f2){
    //     int lcm=denominator*f2.denominator;
    //     int x=lcm/denominator;
    //     int y=lcm/f2.denominator;
    //     int num=(x * numerator) + (y*f2.numerator);
    //     numerator=num;
    //     denominator=lcm;
    //     simplify();
    // }
    //Modifying Added Function for the above to know about operator overloading
    //we will basically return the fraction made by the addition of the two fraction

    // Fraction add(Fraction const & f2){
    //     int lcm=denominator*f2.denominator;
    //     int x=lcm/denominator;
    //     int y=lcm/f2.denominator;
    //     int num=(x * numerator) + (y*f2.numerator);
    //     //storing our result
    //     Fraction fnew(num,lcm);
    //     fnew.simplify();
    //     return fnew;
    // }

    //Now doing overloading

    

    
    //Modifying Added Function for the above to know about operator overloading
    //we will basically return the fraction made by the addition of the two fraction
    //syntax
    //we can make it constant as it just using this for reading not changing this values og the object data members
    const Fraction operator+(Fraction const & f2){
        int lcm=denominator*f2.denominator;
        int x=lcm/denominator;
        int y=lcm/f2.denominator;
        int num=(x * numerator) + (y*f2.numerator);
        //storing our result
        Fraction fnew(num,lcm);
        fnew.simplify();
        return fnew;
    }
    
    void multiply(Fraction const &f2){
        numerator=numerator * f2.numerator;
        denominator=denominator * f2.denominator;
        simplify();
    }
    //overloading the multiply function
    //we can make it constant as it just using this for reading not changing this values og the object data members
    const Fraction operator*(Fraction f2){
        int n=numerator* f2.numerator;
        int d=denominator* f2.denominator;
        Fraction fnew(n,d);
        fnew.simplify();
        return fnew;
    }
    //To check whether to fraction are equal or not
    bool operator==(Fraction const &f2){
        if(numerator== f2.numerator && denominator==f2.denominator) return true;
        return false;
    }
};

int main()
{
    Fraction f1(10,2);
    Fraction f2(15,4);
    
    // Fraction f3=f1.add(f2); //it is ok but we want something like this Fraction f3= f1+f2;
    Fraction f4=f1+f2;  //Fraction f3=f1.add(f2)  here f1 is object and f2 is argument similarly
    Fraction f5=f1*f2;
    f1.print();
    f2.print();
    // f3.print();
    f4.print();
    f5.print();
    bool ans=f1==f2;
    cout<<ans;
    return 0;
}