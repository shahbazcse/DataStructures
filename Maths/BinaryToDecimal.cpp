// CodeHelp
#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter Binary Number: ";
    cin>>n;
    int i=0;
    int ans=0;
    while (n!=0)
    {
        int bit=n%10; // To get bit
        if(bit==1){
            ans=ans+pow(2,i); // To convert Binary form into Decimal form
        }
        n=n/10; // To move to the next digit
        i++;
    }
    cout<<"Decimal Number: "<<ans<<endl; // To print the output
}