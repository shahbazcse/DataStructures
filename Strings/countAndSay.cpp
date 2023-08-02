// Link: https://leetcode.com/problems/count-and-say/

// Approach: Recursion [TC: O(2^N) / SC: O(2^N)]

class Solution {
public:
    string countAndSay(int n) {
        if(n == 0) return "";
        if(n == 1) return "1";

        string str = countAndSay(n-1);

        if(str.size() == 1) return to_string(1)+str;

        string temp = "";
        int i=0;
        int j=str.size();
        while(i < str.size()){
            j = i;
            while(i<str.size() && str[i] == str[j]){
                i++;
            }
            temp += to_string(i-j) + str[j];
        }
        
        return temp;
    }
};