// Link: https://www.codingninjas.com/codestudio/problems/minimum-cost-to-make-string-valid_1115770

// Approach: [TC: O(N) / Aux. SC: O(N)]

#include <bits/stdc++.h> 
int findMinimumCost(string str) {

    if(str.size()%2!=0) return -1;

    stack<char> st;

    for(int i=0; i<str.size(); i++){

      char ch = str[i];

      if(ch == '{'){

        st.push(ch);

      }else if(!st.empty() && st.top() == '{'){

        st.pop();

      }else st.push(ch);

    }

    int a=0;
    int b=0;

    while(!st.empty()){

      if(st.top() == '{'){

        a++;

      }else b++;

      st.pop();
    }

    int ans = (a+1)/2 +(b+1)/2;
    return ans;
}
