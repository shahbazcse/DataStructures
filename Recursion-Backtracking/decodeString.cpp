// Link: https://practice.geeksforgeeks.org/problems/decode-the-string2444/1

// Approach: Stack + Recursion [TC: O(|S|) / SC: O(|S|)]

class Solution{
public:
    void solve(string s, stack<string> &st, int idx){
        if(idx==s.length()) return;
        
        // for digits
        if(isdigit(s[idx])){
            string num;
            while(idx<s.length() && isdigit(s[idx])){
               num += s[idx++];
            }
            st.push(num);
        }
        
        // keeps pushing until we reach end of a substring
        if(s[idx] != ']'){
            st.push(string(1,s[idx]));
        }else{
            // decoding substring
            string temp;
            while(!st.empty() && st.top() != "["){
                temp = st.top() + temp;
                st.pop();
            }
            st.pop();
            
            // repeat substring
            int count = stoi(st.top());
            st.pop();
            
            string res;
            while(count--){
                res = res + temp;
            }
            st.push(res); // store substring in stack to concatenate later
        }
        solve(s,st,idx+1);
    }
    string decodedString(string s){
        stack<string> st;
        solve(s,st,0);
        string ans;
        // concatenating substrings in stack
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};