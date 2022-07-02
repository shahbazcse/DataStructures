#include<iostream>
using namespace std;
/*
Print the pattern given below:
            123
            456
            789
*/

int main(){
    int row, col, count;
    cout<<"Print the no. of rows: ";
    cin>>row;
    col=row;
    count=1;
    while (count<=row*col)
    {
        int temp=1;
        while (temp<=row)
        {
            cout<<count<<" ";
            temp++;
            count++;
        }
        cout<<"\n";
    }
}