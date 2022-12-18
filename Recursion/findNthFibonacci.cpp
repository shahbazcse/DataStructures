#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Problem: Find the Nth Fibonacci Number

int fibonacci(int n){
    // Base condition
    if(n<=1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2); // Multiple recursive calls
/*
 The second call will wait until the first call is completely executed and returns a value.
*/
}

int main(){
    // Function call
    cout<<fibonacci(4)<<endl;

    return 0;
}