// Link: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

// Approach: [TC: O(N) / Aux. SC: O(K)]

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        deque<int> dq;
        vector<int> ans;
        
        // check max in first k elements
        for(int i=0; i<k; i++){
            while(!dq.empty() && arr[i] > dq.front()){
                dq.pop_front();
            }
            
            while(!dq.empty() && arr[i] > dq.back()){
                dq.pop_back();
            }
            
            dq.push_back(arr[i]);
        }
        
        // store max in k window
        if(dq.size()!=0){
            ans.push_back(dq.front());
        }
        
        // check for remaining k windows of array
        for(int i=k; i<n; i++){
            // remove element from front
            if(arr[i-k] == dq.front()) dq.pop_front();
            
            // remove element from front
            while(!dq.empty() && arr[i] > dq.front()){
                dq.pop_front();
            }
            
            // remove element from back
            while(!dq.empty() && arr[i] > dq.back()){
                dq.pop_back();
            }
            
            // store max in k window
            dq.push_back(arr[i]);
            
            if(dq.size()!=0){
                ans.push_back(dq.front());
            }
        }
        // return list containing max elements in K sized windows in the array 
        return ans;
    }
};