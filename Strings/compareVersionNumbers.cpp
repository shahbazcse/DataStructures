// Link: https://leetcode.com/problems/compare-version-numbers/

// Approach: Iterative [TC: O(|S|) / SC: O(1)]

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1=0;
        int v2=0;
        int n1 = version1.size();
        int n2 = version2.size();

        int i=0;
        int j=0;
        while(i<n1 || j<n2){
            // calculate score before '.'
            while(i<n1 && version1[i] != '.'){
                // calculate score by converting the substring into number
                v1 = v1*10+(version1[i]-'0');
                i++;
            }

            // calculate score before '.'
            while(j<n2 && version2[j] != '.'){
                // calculate score by converting the substring into number
                v2 = v2*10+(version2[j]-'0');
                j++;
            }
            
            // check current score and return answer, continue if scores are equal
            if(v1>v2) return 1;
            if(v1<v2) return -1;
            
            // skip dot and evaluate next substring
            i++;
            j++;

            // reset score before evaluating next substring
            v1=0;
            v2=0;
        }

        return 0; // return 0, if versions are equal
    }
};