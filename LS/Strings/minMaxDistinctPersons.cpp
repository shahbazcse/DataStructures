// Link: https://www.geeksforgeeks.org/find-minimum-and-maximum-distinct-persons-entering-or-leaving-the-room/

// Approach: Iterative [TC: O(N) / SC: O(1)]

#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "10101";
    int max,min = -1;
    
    int enter=0;
    int leave=0;
    for(int i=0; i<str.length(); i++){
        if(str[i] == '1') enter++;
        if(str[i] == '0') leave++;
    }
    
    if(enter == 0 || leave ==0){
        if(enter) max = min = enter;
        else max = min = leave;
    }else{
        min = enter - leave;
        max = enter + leave;
    }
    
    cout<<"Minimum Persons: "<< min<<endl;
    cout<<"Maximum Persons: "<< max<<endl;
    
    return 0;
}