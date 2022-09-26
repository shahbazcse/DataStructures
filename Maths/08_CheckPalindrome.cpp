class Solution {
public:
    bool isPalindrome(int x) {
        int temp =x;
        int reverse =0;
        if(temp<0){
            return false;
        }
        while(temp!=0){
            int digit = temp%10;
            if(reverse>INT_MAX/10 || reverse<INT_MIN/10){
                return 0;
            }
            reverse = (reverse*10) + digit;
            temp = temp/10;
        }
        if(reverse == x){
            return true;
        } else return false;
    }
};