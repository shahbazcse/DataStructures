#include<iostream>
using namespace std;
/*
Print the pattern given below:
            1 2 3 4 5 5 4 3 2 1
            1 2 3 4 * * 4 3 2 1
            1 2 3 * * * * 3 2 1
            1 2 * * * * * * 2 1
            1 * * * * * * * * 1
*/

int main(){
    int row, col, tempRow;
    cout<<"Print the no. of rows: ";
    cin>>row;
    tempRow=1;
    while (tempRow<=row){
        col=1;
        while(col<=row-tempRow+1){
            cout<<col;
            col++;
        }
        int star1=tempRow-1;
        while(star1>0){
            cout<<"*";
            star1--;
        }
        int star2=1;
        while (star2<=tempRow-1){
            cout<<"*";
            star2++;
        }
        int col2=row-tempRow+1;
        while (col2>0){
            cout<<col2;
            col2--;
        }
        cout<<"\n";
        tempRow++;
    }
}