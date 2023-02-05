// Link: https://practice.geeksforgeeks.org/problems/immediate-smaller-element1142/1

// Approach: [TC: O(N) / SC: O(1)]

class Solution{
public:	
	void immediateSmaller(vector<int>&arr, int n) {
	    stack<int> st;
        st.push(arr[n-1]);
        arr[n-1]=-1;
    
        for(int i=n-2; i>=0; i--){
            int element = arr[i];
            
    	   if(element>st.top()){
    	       
    	    arr[i]=st.top();
    	    
    	   }else arr[i]=-1;
    	   
            st.pop();
            st.push(element);
    	}
    	st.top();
	}
};