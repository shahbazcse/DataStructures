// Link: https://leetcode.com/problems/longest-common-prefix/

// Approach: Iterative [TC: O(N*M) / SC: O(M)]
// M is the length of the smallest string i.e. miniStr

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // if we have just one string, that is the only LCP
        if(strs.size() == 1) return strs[0];

        // find the smallest sized string in vector of strings (potential LCP)
        int mini = strs[0].size();
        string miniStr = strs[0];
        for(auto it : strs){
            if(mini > it.size()){
                mini = it.size();
                miniStr = it;
            }
        }

        string ans = "";
        for(int i=0; i<strs.size(); i++){
            // to check if atleast one common character is found in every string
            bool found = false;

            // current LCP
            string temp = "";

            // check for current string
            string str = strs[i];
            for(int j=0; j<str.size(); j++){
                // check if common characters at same index are present in both strings and current LCP size should always be smaller than miniStr size
                if(miniStr[j] == str[j] && temp.length()<miniStr.length()){
                    temp += str[j];
                    found = true;
                }else break; // if not further common characters are found, break
            }

            miniStr = temp; // update the current LCP
            ans = temp; // update ans
            if(!found) return ""; // if the current string has no common characters, return empty string
        }
        
        return ans; // return ans;
    }
};