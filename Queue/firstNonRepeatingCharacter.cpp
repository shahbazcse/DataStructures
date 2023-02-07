// Link: https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

// Approach: [TC: O(26*N) / SC: O(26)]

class Solution {
	public:
	string FirstNonRepeating(string A){
        unordered_map<char,int> count;
        queue<char> q;
        string ans = "";
	    
	    for(int i=0; i<A.length(); i++){
	        char ch = A[i];
	        
	        // add/update char count
	        count[ch]++;
	        
	        // push char to queue
	        q.push(ch);
	        
	        // check for non-repeating char at front of queue
	        while(!q.empty()){
	            if(count[q.front()] == 1){
	                ans.push_back(q.front()); // store in ans, if found 
	                break;
	            }else{
	                q.pop(); // pop that repeating char from queue
	            }
	        }
			// if array is empty then no non-repeating char were found, store # in ans
	        if(q.empty()) ans.push_back('#');
	    }
	    return ans;
	}
};