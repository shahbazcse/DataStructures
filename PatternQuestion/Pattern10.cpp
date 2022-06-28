#include<iostream>
using namespace std;
/*
Print the pattern given below:
            1
            21
            321
            4321
*/

int main(){
    int row, col, tempRow, count;
    cout<<"Print the no. of rows: ";
    cin>>row;
    tempRow=1;
    while (tempRow<=row)
    {
        col=1;    
        while(col<=tempRow){
            cout<<tempRow-col+1;
            col++;
        }
        cout<<"\n";
        tempRow++;
    }
}