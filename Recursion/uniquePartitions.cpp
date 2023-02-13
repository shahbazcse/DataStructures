// Link: https://practice.geeksforgeeks.org/problems/unique-partitions1041/1

class Solution{
	public:
/*
	1. This code defines a recursive function "helper" which generates all possible combinations of positive integers that sum up to 
		a given positive integer "n".
	2. The function takes four arguments:
		n: a positive integer representing the target sum.
		idx: a positive integer used as the starting point for generating combinations.
		ds: a reference to a vector of integers, used to store the current combination.
		ans: a reference to a vector of vectors of integers, used to store all the combinations.
	3. The function starts by checking if n is equal to 0. If it is, it pushes the current combination stored in ds into ans and returns.
	4. Next, it checks if idx is less than or equal to 0, and if it is, it returns without doing anything.
	5. The function then checks if idx is less than or equal to n. If it is, it pushes idx into ds and makes a recursive call to the 
		function with n reduced by idx and idx unchanged. After the recursive call returns, it pops idx from ds to restore the state of ds 
		to what it was before the recursive call.
	6. Finally, it makes another recursive call to the function with n unchanged and idx reduced by 1.
	7. In this way, the function generates all possible combinations of positive integers that sum up to n and stores them in ans.
*/
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
/* 
	This code is a function that finds all the unique partitions of a given integer 'n' 
	and stores them in a vector of vectors of integers. It uses a helper function to 
	recursively generate the partitions and store them in the vector 'ans'. 
	The vector 'ds' is used to store the current partition. The variable 'idx' is 
	used to keep track of the current index.
*/
    vector<vector<int>> UniquePartitions(int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        int idx=n;
        
        helper(n,idx,ds,ans);
        return ans;
    }
};