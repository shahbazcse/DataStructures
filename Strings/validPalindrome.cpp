// Link: https://leetcode.com/problems/valid-palindrome/

// Approach: Iterative + Two Pointer [TC: O(|S|) / SC: O(|S|)]

class Solution {
public:
    bool checkPalindrome(string str){
        int l=0;
        int h=str.size()-1;
        while(l<h){
            if(str[l] != str[h]) return false;
            l++;
            h--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string str = "";
        for(int i=0; i<s.size(); i++){
            if(s[i] != ' ' && (s[i] >= 'A' && s[i]<='Z' || s[i] >= 'a' && s[i]<='z' || s[i] >= '0' && s[i]<='9')){
                if(s[i] >= 'A' && s[i]<='Z') str += (s[i]+32);
                else str += s[i];
            }
        }
        return checkPalindrome(str);
    }
};