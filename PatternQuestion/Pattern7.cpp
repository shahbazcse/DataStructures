#include<iostream>
using namespace std;
/*
Print the pattern given below:
            1
            22
            333
            4444
*/

int main(){
    int row, col, tempRow, count;
    cout<<"Print the no. of rows: ";
    cin>>row;
    tempRow=1;
    count=1;
    while (tempRow<=row)
    {
        col=1;
        while (col<=tempRow)
        {
            cout<<tempRow;
            col++;
        }
        count++;
        cout<<"\n";
        tempRow++;
    }
    
}