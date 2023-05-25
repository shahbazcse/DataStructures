// Link: https://leetcode.com/problems/reverse-words-in-a-string

// Approach: Two Pointers [TC: O(|S|) / SC: O(|S|)]

class Solution {
public:
    string reverseWords(string s) {

        int l = 0;
        int h = s.size()-1;

        while(s[l] == ' ') l++;
        while(s[h] == ' ') h--;

        string ans = "";
        while(l<=h){
            while(l<=h && s[l] == ' ') l++;

            string substr = "";
            while(l<=h && s[l] != ' '){
                substr += s[l++];
            }
            ans = substr + " " + ans;
        }

        ans.resize(ans.size()-1);
        return ans;
    }
};