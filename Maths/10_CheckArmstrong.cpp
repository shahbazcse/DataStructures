class Solution {
  public:
    string armstrongNumber(int n){
        int sum = 0;
        int temp = n;
        while(temp!=0){
            int digit = temp%10;
            sum = sum + pow(digit,3);
            temp = temp/10;
        }
        if(sum==n) return "Yes";
        else return "No";
    }
};