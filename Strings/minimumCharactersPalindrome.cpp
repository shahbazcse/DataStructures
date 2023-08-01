// Link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

// Approach: Hashing [TC: O(|S|) / SC: O(|S|)]

class Solution {
public:
    bool isAnagram(string s, string t) {
        // if the size of both strings are not equal, they cannot be an anagram
        if(s.size() != t.size()) return false;
        
        // hash the characters and their frequency
        unordered_map<char,int> mpp;
        for(int i=0; i<s.size(); i++){
            mpp[s[i]]++;
        }

        // reduce the frequency using the characters from other string
        for(int i=0; i<t.size(); i++){
            mpp[t[i]]--;
        }

        // for a valid anagram, after reduction of frequency using other string, all frequency should be zero
        for(auto it : mpp){
            if(it.second != 0) return false; // return false, if any character frequency is found to be non-zero
        }

        return true; // return true, if every character frequency is reduced to zero
    }
};