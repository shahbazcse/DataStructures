#include<iostream>
using namespace std;
/*
Print the pattern given below:
            D
            CD
            BCD
            ABCD
*/

int main(){
    int row, col, tempRow, count;
    cout<<"Print the no. of rows: ";
    cin>>row;
    tempRow=1;
    char alpha;
    while (tempRow<=row)
    {
        col=1;
        alpha='A'+row-tempRow;
        while(col<=tempRow){
            cout<<alpha;
            alpha++;
            col++;
        }
        cout<<"\n";
        tempRow++;
    }
}