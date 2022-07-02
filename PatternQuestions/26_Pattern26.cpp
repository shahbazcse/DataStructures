#include<iostream>
using namespace std;
/*
Print the pattern given below:
               1
              121
             12321
            1234321
*/

int main(){
    int row, col, tempRow;
    cout<<"Print the no. of rows: ";
    cin>>row;
    tempRow=1;
    while (tempRow<=row)
    {
        int space=row-tempRow;
        while(space>0){
            cout<<" ";
            space--;
        }
        col=1;
        while(col<=tempRow){
            cout<<col;
            col++;
        }
        int start=1;
        while(start<=tempRow-1)
        {
            cout<<tempRow-start;
            start++;
        }
        cout<<"\n";
        tempRow++;
    }
}