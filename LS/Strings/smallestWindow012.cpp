// Link: https://practice.geeksforgeeks.org/problems/d6e88f06b273a60ae83992314ac514f71841a27d/1

// Approach: Two Pointer [TC: O(N) / SC: O(1)]

class Solution {
  public:
    int smallestSubstring(string S) {
        int ans = INT_MAX;
        
        // store the index of 0,1, and 2
        int zero = -1, one = -1, two = -1;
        
        for(int i=0; i<S.size(); i++){
            if(S[i] == '0'){
                zero = i;
            }
            else if(S[i] == '1'){
                one = i;
            }
            else if(S[i] == '2'){
                two = i;
            }
            
            // if 0, 1, and 2 are found, then calculate the minimum window length
            if(zero != -1 && one != -1 && two != -1){
                // in every iteration, update the minimum window length
                int maxi = max({zero,one,two});
                int mini = min({zero,one,two});
                ans = min(ans,maxi-mini+1); // update minimum window length
            }
        }
        
        // if any value (0,1,2) is not found, return -1
        if(ans == INT_MAX) return -1;
        
        return ans;
    }
};