// Link: https://practice.geeksforgeeks.org/problems/e015cb4d3f354b035d9665e7c8a54a7aefb1901b/1

// Approach: [TC: O(N) / SC: O(N)]

class Solution {
  public:
    int checkRedundancy(string s) {
        
        stack<char> st;
        
        for(int i=0; i<s.length(); i++){
            
            char ch = s[i];
            
            if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
                
                st.push(ch);
                
            }else if(ch == ')'){
                
                bool flag = true;
                
                while(st.top() != '('){
                    
                    char top = st.top();
                    
                    if(top == '(' || top == '+' || top == '-' || top == '*' || top == '/'){
                        
                        flag = false;    
                        
                    }
                    
                    st.pop();
                }
                
                if(flag) return true;
                
                st.pop();
            }
        }
        return false;
    }
};