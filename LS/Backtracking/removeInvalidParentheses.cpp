// Link: https://practice.geeksforgeeks.org/problems/remove-invalid-parentheses/1

// Approach: Recursion + Backtracking + Stack + Sets [TC: O(2^(|S|)) / SC: O(2^(|S|))]

class Solution {
  public:
    vector<string> ans; // vector to store valid combinations of the input string
    unordered_set<string> set; // set to store already generated combinations
    
    // function to check if a given string of parentheses is valid and return the number of invalid parentheses
    int isValid(string s){
        stack<int> st; // create a stack to store opening parentheses
        
        // iterate through each character in the string
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){ // if the current character is an opening parenthesis, push it onto the stack
                st.push('(');
            }else if(s[i] == ')'){ // if the current character is a closing parenthesis
                if(st.size() == 0){ // if there are no opening parentheses on the stack, push the closing parenthesis onto the stack
                    st.push(')');
                }else if(st.top() == ')'){ // if the top of the stack is also a closing parenthesis, push the current closing parenthesis onto the stack
                    st.push(')');
                }else if(st.top() == '('){ // if the top of the stack is an opening parenthesis, pop it off the stack
                    st.pop();
                }
            }
        }
        return st.size(); // return the number of opening parentheses left on the stack
    }
    
    // recursive function to generate all possible combinations of the input string by removing invalid parentheses
    void solve(string s, int invalid){
        if(invalid < 0) return; // stop recursion if there are more closing parentheses than opening parentheses
        if(invalid == 0){ // base case: no more invalid parentheses left in the string
            int cnt = isValid(s); // check if the resulting string is valid
            if(cnt==0){ // if it is valid, add it to the answer vector
                ans.push_back(s);
            }
            return;
        }
        
        for(int i=0; i<s.size(); i++){ // iterate through each character in the string
            if(s[i] != ')' && s[i] != '(') continue; // skip non-parenthesis characters
            
            string l = s.substr(0,i); // get left substring
            string r = s.substr(i+1); // get right substring
            string temp = l+r; // generate new string by removing current character
            
            if(set.find(temp) == set.end()){ // check if the new string has already been generated
                set.insert(temp); // if not, add it to the set of generated strings
                solve(temp,invalid-1); // recurse on the new string with one less invalid parenthesis
            }
        }
    }
    
    // main function to remove invalid parentheses from the input string
    vector<string> removeInvalidParentheses(string s) {
        int invalidParen = isValid(s); // get the initial number of invalid parentheses in the input string
        solve(s,invalidParen); // generate all possible combinations of the string by removing invalid parentheses
        sort(ans.begin(),ans.end()); // sort the answer vector to reduce the number of solutions returned
        return ans; // return the vector of valid combinations
    }
};