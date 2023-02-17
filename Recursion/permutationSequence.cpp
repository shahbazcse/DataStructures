// Link: https://leetcode.com/problems/permutation-sequence/

// Approach 1: Recursion [TC: O() / Sc: O()]

// Approach 2: Optimized [TC: O(N*N) / SC: O(N)]

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;

        // store all numbers in a list and calculate factorial
        for(int i=1; i<n; i++){
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        string ans;
        
        k--; // reduce by 1 for 0-based indexing

        while(1){
            ans += to_string(numbers[k/fact]);
            numbers.erase(numbers.begin() + k/fact);

            if(numbers.size()==0) break;

            k = k % fact;
            fact = fact / numbers.size();
        }
        return ans;
    }
};