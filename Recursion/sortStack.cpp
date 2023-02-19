// Link: https://practice.geeksforgeeks.org/problems/sort-a-stack/1

// Approach: [TC: O(N^2) / Aux. SC: O(N)]

void helper(stack<int> &s, int num){
    if(s.empty() || s.top()<num){
        s.push(num);
        return;
    }
    
    int n = s.top();
    s.pop();
    
    helper(s,num);
    
    s.push(n);
}

void SortedStack :: sort()
{
    if(s.empty()) return;
    
    int num = s.top();
    s.pop();
    
    sort();
    
    helper(s,num);
}