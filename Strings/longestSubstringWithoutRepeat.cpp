// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Approach: Set [TC: O(NlogN) / SC: O(N)]

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        
        unordered_set<char> set;
        int maxi = -1;

        // windows size
        int i=0;
        int j=0;
        while(i<s.size() && j<s.size()){
            // if character is found in the set, remove it and shrink window size by 1 from left
            if(set.find(s[j]) != set.end()){
                set.erase(s[i]);
                i++;
            }
            // if character is not found in the set, insert it and expand the window size by 1 to right
            else{
                set.insert(s[j++]);
                maxi = max(maxi,j-i); // update maxi, if longer substring is found
            }
        }
        return maxi;
    }
};