// Link: https://leetcode.com/problems/roman-to-integer/

// Approach: Map [TC: O(|S|) / SC: O(|S|)]

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> roman;

        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;


        int ans = 0;

        int curr = 0;
        while(curr != s.length()){
            if(roman[s[curr]] < roman[s[curr+1]]){
                ans -= roman[s[curr]];
            }else{
                ans += roman[s[curr]];
            }
            curr++;
        }

        return ans;
    }
};