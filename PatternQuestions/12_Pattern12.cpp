#include<iostream>
using namespace std;
/*
Print the pattern given below:
            ABC
            ABC
            ABC
*/

int main(){
    int row, col, tempRow;
    cout<<"Print the no. of rows: ";
    cin>>row;
    tempRow=1;
    while (tempRow<=row)
    {
        col=1;
        char alpha=65;
        while(col<=row){
            cout<<alpha;
            alpha++;
            col++;
        }
        cout<<"\n";
        tempRow++;
    }
}