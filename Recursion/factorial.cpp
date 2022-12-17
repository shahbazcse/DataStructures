#include <iostream>
using namespace std;

int factorial(int n){
    // Base condition
    if(n==1)
        return 1;
    return n * factorial(n-1); // Recursive call
}

int main(){
    cout<<factorial(4)<<endl; // Let N=4
    
    return 0;
}