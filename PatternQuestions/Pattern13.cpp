#include<iostream>
using namespace std;
/*
Print the pattern given below:
            ABC
            DEF
            GHI
*/

int main(){
    int row, col, tempRow;
    cout<<"Print the no. of rows: ";
    cin>>row;
    char alpha=65;
    tempRow=1;
    while (tempRow<=row)
    {
        col=1;
        while(col<=row){
            cout<<alpha;
            alpha++;
            col++;
        }
        cout<<"\n";
        tempRow++;
    }
}