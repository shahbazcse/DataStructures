// Link: https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0

// Approach: Using Hashing and Sorting [TC: O(NLogN) / SC: O(N)]

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check(pair<int,int> &a, pair<int,int> &b){
    if(a.first==b.first) return a.second<b.second; // if the count of values in both pairs is same, return the smaller value
    else return a.first>b.first; // else, return the value with greater count
}

void solve(){
    // input
    int N;
	cin>>N;
	
	int A[N];
	
	for(int i=0; i<N; i++){
	    cin>>A[i];
	}
	
	// hash array values
	unordered_map<int,int> m;
	
	for(int i=0; i<N; i++){
	    m[A[i]]++;
	}
	
	// container to store values in the order asked in question
	vector<pair<int,int>> v;
	
	for(auto i:m) v.push_back({i.second,i.first});
	sort(v.begin(),v.end(),check);
	
	// storing values in desired order
	vector<int> ans;
	
	// printing values
	for(auto i:v){
	    int cnt=i.first; // storing count of values
	    while(cnt--){
	        ans.push_back(i.second);
	    }
	}
	
	for(int i=0; i<N; i++) cout<<ans[i]<<" ";
	cout<<endl;
}

int main() {
    // test cases
	int T;
	cin>>T;
	
	for(int i=0; i<T; i++){
	    solve();
	}
	
	return 0;
}

