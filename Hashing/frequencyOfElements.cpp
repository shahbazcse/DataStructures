// Link: https://practice.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/0

// Approach 1: Brute Force [TC: O(N^2)]

class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    int count(int n, vector<int>& arr){
        int cnt=0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==n) cnt++;
        }
        return cnt;
    }
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        vector<int> temp;
        for(int i=1; i<=P; i++){
            int res = count(i,arr);
            temp.push_back(res);
        }
        
        for(int i=0; i<N; i++) arr[i]=temp[i];
    }
};

// Approach 2: Using Hashing [TC: O(N) / SC: O(1)]

class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    {
        unordered_map<int,int> m;
        
        for(int i=0; i<N; i++){
            m[arr[i]]++;
        }
        
        for(int i=0; i<N; i++) arr[i]=m[i+1];
    }
};