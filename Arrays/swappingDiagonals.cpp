// Link: https://www.codechef.com/problems/PROE04

#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
	int arr[n][n]={0};
	
	cout<<"Before"<<endl;
	for(int i=0; i<n; i++){
	    for(int j=0; j<n; j++){
	        cin>>arr[i][j];
	    }
	}
	
	for(int i=0; i<n; i++){
	    for(int j=0; j<n; j++){
	        cout<<arr[i][j]<<" ";
	    }
	    cout<<endl;
	}
	
    // Swapping diagonals
	for(int i=0; i<n; i++){
        swap(arr[i][i],arr[i][n-i-1]);
    }
	
	cout<<"After"<<endl;
	for(int i=0; i<n; i++){
	    for(int j=0; j<n; j++){
	        cout<<arr[i][j]<<" ";
	    }
	    cout<<endl;
	}
	
	return 0;
}
