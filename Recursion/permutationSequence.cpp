// Link: https://leetcode.com/problems/permutation-sequence/

// Approach 1: Recursion [TC: O() / Sc: O()]

// Approach 2: Optimized [TC: O(N*N) / SC: O(N)]

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;

        // store all numbers in a list and calculate factorial (n-1)!
        for(int i=1; i<n; i++){
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        string ans;
        
        k--; // reduce by 1 for 0-based indexing

        while(1){
            // add the first element of required permutation
            ans += to_string(numbers[k/fact]);
            // erase that element from vector
            numbers.erase(numbers.begin() + k/fact);

            // break loop when numbers list is empty and we got our kth sequence
            if(numbers.size()==0) break;

            // find the position for remaining elements
            k = k % fact;
            
            // find the required factorial
            fact = fact / numbers.size();
        }
        return ans;
    }
};