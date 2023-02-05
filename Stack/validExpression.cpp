// Link: https://practice.geeksforgeeks.org/problems/valid-expression1025/1

// Approach: [TC: O(N) / Aux. SC: O(N)]

bool valid(string s)
{
    stack<char> st;
    
    for(int i=0; i<s.size(); i++){

        char ch = s[i];

        if(ch == '(' || ch == '[' || ch == '{'){

            st.push(ch);

        }else if(!st.empty()){

                char top = st.top();

                if( top == '(' && ch == ')' ||
                    top == '{' && ch == '}' ||
                    top == '[' && ch == ']')
                {
                    st.pop();
                }
                else return false;

        }else return false;
    }
    
    if(st.empty()) return true;
    else return false;
}