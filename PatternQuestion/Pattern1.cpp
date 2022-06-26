#include<iostream>
using namespace std;
/*
Print the pattern given below:
            ****
            ****
            ****
            ****
*/

int main(){
    int row, col, temp;
    cout<<"Print the no. of rows:";
    cin>>row;
    temp=1;
    while (temp<=row)
    {
        col=1;
        while (col<=row)
        {
            cout<<col;
            col++;
        }
        cout<<"\n";
        temp++;
    }
}