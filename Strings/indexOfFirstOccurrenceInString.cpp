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

// Approach 2: Z Function [TC: O() / SC: O()]



// Approach 3: KMP Algorithm / LPS(pi) Array [TC: O() / SC: O()]

