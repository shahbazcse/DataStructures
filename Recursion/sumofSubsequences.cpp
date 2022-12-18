#include<bits/stdc++.h>
using namespace std;

// Problem: Print all the subsequences in an Array whose sum is K

// void checkSubsequence(int idx, vector<int> &sub, int arr[], int K, int size, int &key){
//     // Base condition
//     if(idx==size){
//         if(key==K){
//             for(auto it : sub) cout<<it<<" ";
//             cout<<endl;
//         }
//         return;
//     }
//     // Multiple recursive calls
    
//     // Not-take condition
//     checkSubsequence(idx+1,sub,arr,K,size,key);

//     // Take condition
//     sub.push_back(arr[idx]);
//     key+=arr[idx];

//     checkSubsequence(idx+1,sub,arr,K,size,key);
    
//     sub.pop_back();
//     key-=arr[idx];
// }

// Problem: Print the first subsequence in an Array whose sum is K

// bool checkSubsequence(int idx, vector<int> &sub, int arr[], int K, int size, int &key){
//     // Base condition
//     if(idx==size){
//         if(key==K){
//             for(auto it : sub) cout<<it<<" ";
//             cout<<endl;
//             return true;
//         }
//         else return false;
//     }
//     // Multiple recursive calls
    
//     // Not-take condition
//     if(checkSubsequence(idx+1,sub,arr,K,size,key)==true) return true;

//     // Take condition
//     sub.push_back(arr[idx]);
//     key+=arr[idx];

//     if(checkSubsequence(idx+1,sub,arr,K,size,key)==true) return true;
    
//     sub.pop_back();
//     key-=arr[idx];
    
//     return false;
// }

// Problem: Print the total count of subsequences in an Array whose sum is K

int checkSubsequence(int idx, int arr[], int K, int size, int &key){
    // Base condition
    if(key>K) return 0;
    if(idx==size){
        if(key==K){
            return 1;
        }
        return 0;
    }
    // Multiple recursive calls
    
    // Not-take condition
    int l = checkSubsequence(idx+1,arr,K,size,key);

    // Take condition
    key+=arr[idx];

    int r = checkSubsequence(idx+1,arr,K,size,key);
    
    key-=arr[idx];

    return l+r;
}

int main(){
    int arr[] = {1,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);

    int K = 2;

    vector<int> sub;
    int key=0;

    // Function call
    cout<<checkSubsequence(0,arr,K,size,key)<<endl;
    

}