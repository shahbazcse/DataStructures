#include<iostream>
using namespace std;
/*
Print the pattern given below:
               *
              **
             ***
            ****
*/

int main(){
    int row, col, tempRow, space;
    cout<<"Print the no. of rows: ";
    cin>>row;
    tempRow=1;
    while (tempRow<=row)
    {
        space=row-tempRow;
        while (space>0)
        {
            cout<<" ";
            space--;
        }
        col=1;
        while (col<=tempRow)
        {
            cout<<"*";
            col++;
        }
        cout<<"\n";
        tempRow++;
    }
}