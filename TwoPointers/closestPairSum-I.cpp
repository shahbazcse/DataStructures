// Link: https://practice.geeksforgeeks.org/problems/pair-in-array-whose-sum-is-closest-to-x1124/0

// Approach: 2 Pointers + Binary Search [TC: O(N)]

class Solution{   
public:
    vector<int> sumClosest(vector<int>arr, int x)
    {
        vector<int> ans(1,0);
        int size=arr.size();
        int s=0;
        int e=size-1;
        int diff=INT_MAX;
        while(s<e){
            int sum=arr[s]+arr[e];
            if(diff>abs(sum-x)){
                diff=abs(sum-x);
                ans={arr[s],arr[e]};
            }
            if(x<sum) e--;
            else s++;
        }
        return ans;
    }
};