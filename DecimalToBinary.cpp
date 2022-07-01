// CodeHelp
#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter Decimal Number: ";
    cin>>n;
    int ans=0;
    int i=0;
    while(n!=0){
        int bit=n&1; // To get bit
        ans=(bit*pow(10,i))+ans; // To reverse the number
        n=n>>1; // To move to next digit
        i++;
    }
    cout<<"Binary Number: "<<ans<<endl;
}