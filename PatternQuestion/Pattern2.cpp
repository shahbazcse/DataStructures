#include<iostream>
using namespace std;
/*
Print the pattern given below:
            111
            222
            333
*/

int main(){
    int row, col, tempRow;
    cout<<"Print the no. of rows: ";
    cin>>row;
    tempRow=1;
    while (tempRow<=row)
    {
        col=1;
        while (col<=row)
        {
            cout<<tempRow;
            col++;
        }
        cout<<"\n";
        tempRow++;
    }
}