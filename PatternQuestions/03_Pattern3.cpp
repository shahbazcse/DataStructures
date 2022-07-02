#include<iostream>
using namespace std;
/*
Print the pattern given below:
            1234
            1234
            1234
            1234
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
            cout<<col;
            col++;
        }
        cout<<"\n";
        tempRow++;
    }
}