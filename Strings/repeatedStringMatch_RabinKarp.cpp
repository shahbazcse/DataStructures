// Link: https://leetcode.com/problems/repeated-string-match/

// Approach 1: String find() [TC: O((M^2)/N) / SC: O(M)]
// M = size of string a, N = size of string b

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string str = "";
        int cnt = 0;

        // repeat string a until the size becomes greater or equal to string b
        while(str.size() < b.size()){
            str += a;
            cnt++; // increment count after every repeatition
        }

        // check whether string b is found in string str, if not found it return string::npos(or -1)
        if(str.find(b) != string::npos) return cnt;

        // repeat once more as maybe few values from the end of string b maybe missing that can be covered in next repeatition
        str += a;
        cnt++; // increment coutn after repeatition

        // check whether string b is found in string str, if not found it return string::npos(or -1)
        if(str.find(b) != string::npos) return cnt;

        return -1; // if strings are not matched, return -1
    }
};

