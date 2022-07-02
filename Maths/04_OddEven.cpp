#include<iostream>
#include<cstring>
using namespace std;

class OddEven{
    public:
        void isOdd(int x){
            if(x&1==1){
                cout<<"Odd number"<<endl;
            }
            else cout<<"Even number"<<endl;
        }
};
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    OddEven check;
    check.isOdd(n);
}