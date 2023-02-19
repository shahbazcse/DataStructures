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

// Approach 2: Recursion [TC: O(str.length)]

class Solution{
  public:
    int atoiRec(int &i, int &sum, string &str){
        if(i==str.length()) return true;
        
        if(!(str[i]-'0'>=0 && str[i]-'0'<=9)) return false;

        sum=sum*10+str[i]-'0';
        i++;
        return atoiRec(i,sum,str);
    }
    /*You are required to complete this method */
    int atoi(string str) {
        int sum=0;
        int sign=1;
        bool flag;
        int i=0;
        
        if(str[0]=='-'){
            sign=-1;
            i++;
            flag=atoiRec(i,sum,str);
        }
        else flag=atoiRec(i,sum,str);
        
        return (flag) ? sign*sum : -1;
    }
};