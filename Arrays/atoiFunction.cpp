// Link: https://practice.geeksforgeeks.org/problems/implement-atoi/1

// Approach 1: [TC: O(str.length)]

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int sum=0;
        int sign=1;
        
        for(int i=0; i<str.length(); i++){
            if(str[i]=='-' && i==0){
                sign=-1;
                i++;
            }
            if(!(str[i]-'0'>=0 && str[i]-'0'<=9)) return -1;
            sum=sum*10+str[i]-'0';
        }
        return sign*sum;
    }
};