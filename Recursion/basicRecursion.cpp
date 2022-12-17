#include<iostream>
using namespace std;

// Problem 1: Print Name N times
void printNTimes(int n){
    // Base condition
    if(n=0)
        return;
    cout<<"John"<<endl;
    // Recursive call
    printNTimes(n-1);
}

// Problem 2: Print Linearly from 1 to N
void print1ToN(int i, int n){
    // Base condition
    if(i>n)
        return;
    // Recurive call
    cout<<i<<endl;
    print1ToN(i+1,n);
}

// Problem 3: Print from N to 1
void printNto1(int i, int n){
    // Base condition
    if(i<1)
        return;
    // Recursive call
    cout<<i<<endl;
    printNto1(i-1,n);
}

// Problem 4: Print linearly from 1 to N using backtracking
void print1ToNbackT(int i, int n){
    // Base condition
    if(i<1)
        return;
    // Recurive call
    print1ToNbackT(i-1,n);
    cout<<i<<endl;
}

// Problem 5: Print linearly from N to 1 using backtracking
void printNto1backT(int i, int n){
    // Base condition
    if(i>n)
        return;
    // Recursive call
    printNto1backT(i+1,n);
    cout<<i<<endl;
}

int main(){
    // Function calls

    // printNTimes(5); // Let N=5
    // print1ToN(1,4); // Let N=4
    // printNto1(4,4); // Let N=4
    // print1ToNbackT(4,4); // Let N=4
    // printNto1backT(1,4); // Let N=4

    return 0;
}