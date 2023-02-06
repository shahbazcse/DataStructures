// Link: https://practice.geeksforgeeks.org/problems/max-rectangle/1

// Approach: [TC: O(N*M) / SC: O(M)]

class Solution{
  private:
    vector<int> nextSmallerElement(int *arr, int n){
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

    vector<int> prevSmallerElement(int *arr, int n){
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

    int largestRectangleArea(int *heights, int n) {

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
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        
        int maxArea = largestRectangleArea(M[0],m); // find area of rectangle in first row
        
        // find area of rectangle in (1th + 2nd) rows, then (1th + 2nd + 3rd) rows.., upto (1th + 2nd + 3rd + (n-1)th) rows 
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(M[i][j] > 0) M[i][j] += M[i-1][j];
                else M[i][j] = 0;
            }
            // Each time calculate new area of the summed up rows
            int newArea = largestRectangleArea(M[i],m);
            maxArea = max(maxArea,newArea); // update max area
        }
        return maxArea;
    }
};