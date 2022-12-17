#include <bits/stdc++.h>
using namespace std;

// Problem: Reverse an array using Recursion

void reverseArray(int start, int arr[], int end){
    // Base condition
    if(start>=end/2)
        return;
    // Swapping using 2-Pointer Technique
    swap(arr[start],arr[end-start-1]);
    // Recursive call
    reverseArray(start+1,arr,end);
}

int main(){
    int arr[5]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);

    // Function call
    reverseArray(0,arr,size);
    
    for(int i=0; i<size; i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}