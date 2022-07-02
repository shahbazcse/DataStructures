#include<iostream>
using namespace std;

class Prime{
    public:
        int value;
    public:
        void checkPrime(int x){
            if(x%2 ==! 0)
                cout<<x<<" is a Prime number";
            else
                cout<<x<<" is not a Prime number";
        }
};

int main(){
    int value;
    cout<<"Enter a number to check whether its prime or not: ";
    cin>>value;
    Prime check;
    check.checkPrime(value);
}