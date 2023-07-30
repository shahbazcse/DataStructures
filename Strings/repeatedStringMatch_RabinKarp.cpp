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

// Approach 2: Rabin Karp [TC: O(N*M) / SC: O(N*M)]

class Solution {
private:
    int mod = 1e7; // A constant to be used for modulo operations

public:
    // Rabin-Karp algorithm to check if 'target' is a substring of 'source'
    bool rabinKarp(string source, string target) {
        if (source == "" || target == "") return false; // If either string is empty, there's no match

        int m = target.size(); // Length of the target string

        int targetCode = 0; // Hash code for the target string
        for (int i = 0; i < m; i++) {
            targetCode += (target[i] * 26) % mod; // Calculating the hash code using simple hashing
        }

        int hashCode = 0; // Current hash code for the sliding window in the source string
        for (int i = 0; i < source.size(); i++) {
            hashCode = (hashCode + (source[i] * 26)) % mod; // Update the hash code for the current window
            
            // If the current window doesn't have 'm' characters yet, continue to the next iteration
            if (i < m - 1) continue;

            // If the current window has 'm' characters, remove the oldest character from the window
            // by subtracting its hash contribution from the current hash code
            if (i >= m) {
                hashCode = (hashCode - (source[i - m] * 26)) % mod;
            }

            // Check if the current window's hash code matches the target's hash code
            // and if the substring of 'source' in the current window matches 'target'
            if (hashCode == targetCode && source.substr(i - m + 1, m) == target) {
                return true; // If both conditions are met, we found a match
            }
        }
        return false; // If no match is found, return false
    }

    // Function to find the minimum number of times 'a' should be repeated to form 'b'
    int repeatedStringMatch(string a, string b) {
        if (a == b) return 1; // If 'a' and 'b' are identical, 'a' is repeated once to get 'b'

        int cnt = 1; // Initialize the repetition count of 'a'
        string source = a; // Initialize 'source' with 'a'

        // Keep appending 'a' to 'source' until its length is greater than or equal to 'b'
        while (source.size() < b.size()) {
            cnt++; // Increment the repetition count
            source += a; // Append 'a' to 'source'
        }

        if (source == b) return cnt; // If 'source' is equal to 'b', return the repetition count 'cnt'

        // Check if 'b' is a substring of 'source' using the rabinKarp function
        if (rabinKarp(source, b)) return cnt;

        // Check if 'b' is a substring of 'source + a' (considering one more repetition of 'a')
        if (rabinKarp(source + a, b)) return cnt + 1;
        else return -1; // If 'b' cannot be formed by repeating 'a', return -1
    }
};