// Link: https://www.geeksforgeeks.org/find-the-substring-with-maximum-frequency-and-containing-only-x-and-y/

// Approach: Hashing [TC: O(N^2) / SC: O(N)]

#include <bits/stdc++.h>
using namespace std;

void updateFrequency(string str, unordered_map<char,int> mpp, char &ans){
    int maxi = INT_MIN;
    for(auto it : mpp){
        if(maxi == it.second){
            ans = INT_MIN;
            continue;
        }
        if(maxi < it.second){
            maxi = it.second;
            ans = it.first;
        }
    }
}

int main() {
    string S = "22772777";
    int N = S.size();
    char X = '2';
    char Y = '7';
    
    if(N == 1){
        cout<<S;
        return 0;
    }else if(N == 0){
        cout<<"Empty String";
        return 0;
    }
    
    char ans;
    
    unordered_map<char,int> mpp;
    bool foundX = false;
    bool foundY = false;
    
    for(int i=0; i<N; i++){
        mpp[S[i]]++;
        
        if(S[i] == X) foundX = true;
        if(S[i] == Y) foundY = true;
        
        if(foundX && foundY) updateFrequency(S.substr(0,i),mpp,ans);
    }
    
    isdigit(ans) ? cout<<ans : cout<<"All substrings have equal frequency";

    return 0;
}