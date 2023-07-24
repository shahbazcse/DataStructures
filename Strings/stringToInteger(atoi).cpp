// Link: https://leetcode.com/problems/string-to-integer-atoi/

// Approach: Iterative [TC: O(|S|) / SC: O(1)]

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        
        int neg = false;
        int pos = false;

        double num = 0;

        while(s[i] == ' '){
            i++;
        }
        if(s[i] == '-'){
            neg = true;
            i++;
        }
        if(s[i] == '+'){
            pos = true;
            i++;
        }
        
        while(i<n && s[i] >= '0' && s[i] <= '9'){            
            num = num*10 + (s[i]-'0');
            i++;
        }

        if(neg) num = -num;
        if(neg && pos) return 0;
        if(num > INT_MAX) return INT_MAX;
        if(num < INT_MIN) return INT_MIN;

        return num;
    }
};