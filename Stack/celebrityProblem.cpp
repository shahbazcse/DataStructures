// Link: https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

// Approach 1: Brute Force [TC: O(N^2) / SC: O(1)]

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int idx=-1;
        bool celeb;
        int cnt=0;
        for(int i=0; i<n; i++){
            celeb=true;
            for(int j=0; j<n; j++){
                if(M[i][j]==1){
                    celeb=false;
                    break;
                }
            }
            if(celeb){
                cnt++;
                idx=i;
            }
        }
        if(cnt==1) return idx;
        else return -1;
    }
};

// Approach 2: Using Stack [TC: O(N) / SC: O(1)]

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        
        for(int i=0; i<n; i++){
            st.push(i);
        }
        while(st.size()!=1){
            int a=st.top();
            st.pop();
            
            int b=st.top();
            st.pop();
            
            if(M[a][b]==1){
                st.push(b);
            }else st.push(a);
        }
        
        bool rowCheck = true;
        
        for(int i=0; i<n; i++){
            if(M[st.top()][i]!=0) rowCheck=false;
        }
        
        bool colCheck = true;
        
        for(int i=0; i<n; i++){
            if(i!=st.top() && M[i][st.top()]!=1) colCheck=false;
        }
        
        if(rowCheck && colCheck) return st.top();
        else return -1;
    }
};