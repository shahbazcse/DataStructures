// Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

// Approach 1: Recursion [TC: O(N*M) / SC: O(N)]
// N = size of haystack string, M = size of needle string

class Solution {
public:
    int findFirstIndex(string source, string target, vector<int> &allOccurences){
        if(allOccurences.size() == 0) return -1;

        int j=allOccurences[0];
        for(int i=0; i<target.size(); i++){
            if(target[i] != source[j++]){
                allOccurences.erase(allOccurences.begin());
                return findFirstIndex(source,target,allOccurences);
            }
        }
        
        return allOccurences[0];
    }
    int strStr(string haystack, string needle) {
        vector<int> allOccurences;
        for(int i=0; i<haystack.size(); i++){
            if(needle[0] == haystack[i]){
                 allOccurences.push_back(i);
            }
        }

        return findFirstIndex(haystack,needle,allOccurences);
    }
};

// Approach 2: Z Function [TC: O(M+N) / SC: O(M+N)]

class Solution {
public:
    int strStr(string haystack, string needle) {
        string P = needle; // Store the needle in a separate string P
        string T = haystack; // Store the haystack in a separate string T
        int m = P.size(); // Length of the needle

        string str = P + "$" + T; // Concatenate needle and haystack with a delimiter '$'

        vector<int> Z(str.size(), 0); // Initialize Z array with all zeros
        int L, R = 0; // Pointers for the Z-box (left and right boundaries)

        // Z algorithm to construct the Z array
        for (int i = 1; i < str.size(); i++) {
            if (i > R) {
                // If i is outside the current Z-box, we need to start a new comparison
                L = R = i; // Set both pointers to i
                while (R < str.size() && str[R] == str[R - L]) {
                    // Increment R until we find a mismatch or reach the end of the string
                    R++;
                }
                Z[i] = R - L; // Store the length of the common prefix
                R--; // Decrement R to the rightmost index of the current Z-box
            } else {
                int K = i - L; // Corresponding index in the Z-box
                if (Z[K] < R - i + 1) {
                    // If Z[K] is within the current Z-box, we can use the previous value
                    Z[i] = Z[K];
                } else {
                    // Otherwise, we need to start a new comparison
                    L = i;
                    while (R < str.size() && str[R] == str[R - L]) {
                        // Increment R until we find a mismatch or reach the end of the string
                        R++;
                    }
                    Z[i] = R - L; // Store the length of the common prefix
                    R--; // Decrement R to the rightmost index of the current Z-box
                }
            }
        }

        // Check if there is a match in the Z array
        for (int i = 0; i < str.size(); i++) {
            if (Z[i] == m) {
                // If the Z value at index i equals the length of the needle, we found a match
                return (i - m - 1); // Return the starting index of the first occurrence
            }
        }

        return -1; // If the needle is not found, return -1.
    }
};

// Approach 3: KMP Algorithm / LPS(pi) Array [TC: O() / SC: O()]

