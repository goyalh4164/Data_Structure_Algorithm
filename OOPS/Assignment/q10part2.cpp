#include<bits/stdc++.h>
using namespace std;
class B{
    friend void counter_zero(B & counter);
    friend B operator+(B c1,B c2);
    private:
    int count;
    public:
    B(int count) :count(count) {}
    void print(){
        cout<<count<<endl;
    }
    void increment(){
        count++;
    }
};
void counter_zero(B & counter){
    counter=0;
}
B operator+(B c1,B c2){
    B new_counter=c1.count + c2.count;
    return new_counter;
}
int main()
{
    B counter1(5);
    counter1.increment();
    counter1.print();

    B counter2(2);
    counter2.print();

    B counter3=counter1 +counter2;
    counter3.print();
    counter_zero(counter3);
    counter3.print();
    return 0;
}