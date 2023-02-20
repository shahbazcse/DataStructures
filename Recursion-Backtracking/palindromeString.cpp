#include <iostream>
using namespace std;

// Problem: Check whether a String is Palindrome or not using Recursion

bool checkPalindrome(int start, string &str){
    // Base condition
    if(start>str.size()/2)
        return true;
    // Base condition
    if(str[start]!=str[str.size()-start-1])
        return false;
    // Recursive call
    return checkPalindrome(start+1,str);
}

int main(){

    string str = "tenet";

    // Function call
    cout<<checkPalindrome(0,str)<<endl;

    return 0;
}