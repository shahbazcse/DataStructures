// Approach 1: Using flag array for marking fixed/not-fixed index

class Solution {
public:
    void allPermutations(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, int flag[]){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!flag[i]){
                ds.push_back(nums[i]);
                flag[i]=1;
                allPermutations(nums,ds,ans,flag);
                ds.pop_back();
                flag[i]=0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        int size = sizeof(nums)/sizeof(nums[0]);
        int flag[size];
        for(int i=0; i<size; i++) flag[i]=0;
        allPermutations(nums,ds,ans,flag);
        return ans;
    }
};

// Approach 2: Using swap()

class Solution {
public:
    void allPermutations(int idx,vector<int> &nums, vector<vector<int>> &ans){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=idx; i<nums.size(); i++){
            swap(nums[idx],nums[i]);
            allPermutations(idx+1,nums,ans);
            swap(nums[idx],nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        allPermutations(0,nums,ans);
        return ans;
    }
};