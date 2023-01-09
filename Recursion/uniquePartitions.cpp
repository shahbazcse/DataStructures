// Link: https://practice.geeksforgeeks.org/problems/unique-partitions1041/1

class Solution{
	public:
	void helper(int n, int idx, vector<int> &ds, vector<vector<int>> &ans){
	    if(n==0){
	        ans.push_back(ds);
	        return;
	    }
	    if(idx<=0){
	        return;
	    }
	    
	    if(idx<=n){
            ds.push_back(idx);
    	    helper(n-idx,idx,ds,ans);
    	    ds.pop_back();
	    }
	    helper(n,idx-1,ds,ans);
	}
    vector<vector<int>> UniquePartitions(int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        int idx=n;
        
        helper(n,idx,ds,ans);
        return ans;
    }
};