// Link: https://leetcode.com/problems/longest-palindromic-substring

// Approach 1: Priority Queue - Passed Test Cases: (71/141) [TC: O(N^2) / SC: O(N^2)]

class Solution {
public:
    bool isPalindrome(string str){
        int s = 0;
        int e = str.size()-1;
        while(s<=e){
            if(str[s++]!=str[e--]) return 0;
        }
        return 1;
    }
    string longestPalindrome(string s) {
        priority_queue<pair<int,string>> pq;
        int idx=0;

        while(idx < s.size()){
            string str = "";
            int l = idx;
            while(l < s.size()){
                str = str + s[l++];
                if(isPalindrome(str)){
                    pq.push({str.size(),str});
                }
            }
            idx++;
        }

        return pq.top().second;
    }
};

// Approach 2: DP Optimized [TC: O() / SC: O()]

