// Link: https://leetcode.com/problems/largest-rectangle-in-histogram/

// Approach: [TC: O(N) / SC: O(N)]

class Solution {
public:
    vector<int> nextSmallerElement(vector<int> arr, int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
    
        for(int i=n-1; i>=0; i--){
            int element = arr[i];
            while(st.top()!=-1 && arr[st.top()] >= element){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
    	}
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> arr, int n){
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
    
        for(int i=0; i<n; i++){
            int element = arr[i];
            while(st.top()!=-1 && arr[st.top()] >= element){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
    	}
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallerElement(heights,n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights,n);
        
        int maxi=INT_MIN;

        for(int i=0; i<n; i++){
            int l=heights[i];

            if(next[i]==-1) next[i]=n;
            int b= next[i]-prev[i]-1;
            
            int area = l*b;
            maxi = max(maxi,area);
        }
        return maxi;
    }
};