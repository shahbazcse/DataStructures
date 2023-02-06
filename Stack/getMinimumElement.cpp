// Link: https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1

// Approach: [TC: O(1) / SC: O(1)]

class Solution{
    int minEle;
    stack<int> s;
    public:
       /*returns min element from stack*/
       int getMin(){
           if(s.empty()) return -1;
           else return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(s.empty()) return -1;
           
           if(s.top()>0){
               int top = s.top();
               s.pop();
               return top;
           }else{
               int val = minEle;
               minEle = minEle+abs(s.top());
               s.pop();
               return val;
           }
       }
       
       /*push element x into the stack*/
       void push(int x){
            if(s.empty()){
                minEle=x;
                s.push(x);
            }
            else if(x>minEle){
                s.push(x);
            }
            else{
                int val = minEle;
                minEle = x;
                s.push(x-val);
            }
            return;
       }
};