#include <iostream>
using namespace std;

// Problem: Find the sum of first N numbers

// Parameterised Recursion
void doSumParam(int n, int sum){
    // Base condition
    if(n<1){
        cout<<sum<<endl;
        return;
    }
    // Recursive call
    doSumParam(n-1, sum+n);
}

// Functional Recursion
int doSumFunc(int n){
    // Base condition
    if(n==0)
        return 1;
    return n * doSumFunc(n-1); // Recursive call
}

int main(){
    // Function call
    // doSumParam(3,0); // Let N=3
    cout<<doSumFunc(3)<<endl; // Let N=3

    return 0;
}