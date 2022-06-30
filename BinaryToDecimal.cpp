// CodeHelp
#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i=0;
    int ans=0;
    while (n!=0)
    {
        int bit=n%10; // bit is in the form of digit, hence the formula
        if(bit==1){
            ans=ans+pow(2,i);
        }
        n=n/10;
        i++;
    }
    cout<<ans<<endl;
}