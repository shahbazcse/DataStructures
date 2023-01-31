// Link: https://practice.geeksforgeeks.org/problems/b6b608d4eb1c45f2b5cace77c4914f302ff0f80d/1

// Approach: [TC: O(NLogN)]

class Solution
{   
public:
    long long smallestpositive(vector<long long> array, int n)
    { 
        sort(array.begin(),array.end());
        
        long long res=1;
        
        for(auto i:array){
            if(res<i) return res;
            res+=i;
        }
        return res;
    } 
};