#include<iostream>
using namespace std;
/*
Print the pattern given below:
            1234
             234
              34
               4
*/

int main(){
    int row, col, tempRow;
    cout<<"Print the no. of rows: ";
    cin>>row;
    tempRow=1;
    while (tempRow<=row)
    {
        int space=1;
        while(space<=tempRow-1){
            cout<<" ";
            space++;
        }
        col=1;
        while(col<=row-tempRow+1){
            cout<<col+tempRow-1;
            col++;
        }
        cout<<"\n";
        tempRow++;
    } 
}