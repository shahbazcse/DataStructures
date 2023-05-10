// Link: https://practice.geeksforgeeks.org/problems/alien-dictionary/1

// Approach: DFS + Topological Sort [TC: O((N*|S|)+K) / SC: O(K)]

class Solution{
    public:
    // DFS Topological Sort
    void dfs(int node, int vis[], vector<int> adj[], stack<int> &st){
	    vis[node] = 1;
	    
	    for(int it : adj[node]){
	        if(!vis[it]){
	            dfs(it,vis,adj,st);
	        }
	    }
	    // store the current node in stack after making the recursive calls for its adjacent nodes above, because current node will always come before its adjacent nodes
	    st.push(node);
	}
    string findOrder(string dict[], int N, int K) {
        // creating adjacency list
        vector<int> adj[K];
        for(int i=0; i<N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(),s2.size());
            
            // check for precendence order of the alphabets in the string pairs 's1' and 's2'
            for(int j=0; j<len; j++){
                // if first different character is found, store it in adjacency list and break out and check for next pairs
                if(s1[j]!=s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a'); // converting 'char' to 'int'
                    break;
                }
            }
        }
        
        // to keep track of the visited nodes
	    int vis[K] = {0};
        // for storing the nodes in topologically sorted order after visiting the node
	    stack<int> st;
	    
        // check for all connected components
	    for(int i=0; i<K; i++){
	        if(!vis[i]){
	            dfs(i,vis,adj,st);
	        }
	    }
	    
        // constructing the answer string
	    string ans = "";
	    while(!st.empty()){
	        ans += char(st.top() + 'a'); // converting 'int' to 'char'
	        st.pop();
	    }
	    return ans;
    }
};