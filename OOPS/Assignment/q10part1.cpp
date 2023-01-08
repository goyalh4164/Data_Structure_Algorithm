#include<bits/stdc++.h>
using namespace std;

class B{
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
    B operator+(B const & counter){
        B new_counter(count +counter.count);
        return new_counter;
    }
};
int main()
{
    B counter1(5);
    counter1.increment();
    counter1.print();

    B counter2(2);
    counter2.print();

    B counter3 =counter1 + counter2;
    counter3.print();

    return 0;
}