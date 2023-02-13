// Link: 

// Approach: [TC: O() / SC: O()]

class Solution {
public:
    void findCombination(int idx, vector<int> &candidates, int target, vector<int> &ds, vector<vector<int>> &ans){
        // Base condition
        if(idx==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        // Take
        if(candidates[idx] <= target){
            ds.push_back(candidates[idx]);
            findCombination(idx,candidates,target-candidates[idx],ds,ans);
            ds.pop_back();
        }
        // Not-take
        findCombination(idx+1,candidates,target,ds,ans);

        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0,candidates,target,ds,ans);
        return ans;
    }
};