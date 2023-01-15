// Link: https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1

// Approach 1: Using Sorting + 4 Pointers + Binary Search [TC: O(N*N*N)]

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        int size=arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end()); // Sorting
        // 4 Pointer - i,j,s,e
        for(int i=0; i<size-3; i++){
            for(int j=i+1; j<size-2; j++){
                int s=j+1;
                int e=size-1;
                // Binary Search
                while(s<e){
                    int sum=arr[i]+arr[j]+arr[s]+arr[e];
                    if(sum==k){
                        
                        vector<int> temp;
                        
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[s]);
                        temp.push_back(arr[e]);
                        ans.push_back(temp);
                        
                        // Ignoring Duplicates
                        while(s<e && arr[s]==arr[s+1]) s++;
                        while(s<e && arr[e]==arr[e-1]) e--;
                        
                        s++;
                        e--;
                    }else if(sum<k) s++;
                    else e--;
                }
                // Ignoring Duplicates
                while(j<size && arr[j]==arr[j+1]) j++;
            }
            // Ignoring Duplicates
            while(i<size && arr[i]==arr[i+1]) i++;
        }
        return ans;
    }
};
    }
};