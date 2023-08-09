// Link: https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/description/

// Approach: Iterative [TC: O(N) / SC: O(1)]

class Solution {
public:   
    int minimumPartition(string s, int k) {
        int part = 0;
        long long val = 0;
        
        for(int i = 0; i<s.length(); i++){
            val = val*10 + s[i]-'0';
            if(val <= k) continue;
            else if(val > k){
                part++;
                val = s[i]-'0';
                if(val > k) return -1;
            }
        }
        
        if(val > k) return -1;
        else return part+1;
    }
};