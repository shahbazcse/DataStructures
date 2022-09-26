class Solution{
public:
    int evenlyDivides(int N){
        int temp=N;
        int noOfDigits=0;
        while(temp>0){
            int digit = temp%10;
            if(digit!=0){
                if((N%digit) == 0){
                    noOfDigits++;
                }   
            }
            temp = temp/10;
        }
        return noOfDigits;
    }
};