// Link: https://www.geeksforgeeks.org/minimum-partitions-of-string-such-that-each-part-is-at-most-k/

// Approach: Iterative [TC: O(N) / SC: O(1)]

#include<bits/stdc++.h>
using namespace std;

int minimumPartitions(string s, int k){
    int part = 0;
    int val = 0;
    int i = 0;
    while(i<=s.length()){
        if(val >= k){
            part++;
            i--;
            val = 0;
        }
        else{
            val = val*10 + s[i]-'0';
            i++;
        }
        if(i==s.length() && val > k){
            part++; 
            break;
        }
    }
    
    if(part) return part;
    else return -1;
}

int main() {
    string s = "7891634";
    int k = 21;
    
    cout<<minimumPartitions(s,k);
    
    return 0;
}