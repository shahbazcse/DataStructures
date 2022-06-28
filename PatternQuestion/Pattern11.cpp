#include<iostream>
using namespace std;
/*
Print the pattern given below:
            AAA
            BBB
            CCC
*/

int main(){
    int row, col, tempRow;
    cout<<"Print the no. of rows: ";
    cin>>row;
    tempRow=1;
    char alpha=65;
    while (tempRow<=row)
    {
        col=1;
        while(col<=row){
            cout<<alpha;
            col++;
        }
        cout<<"\n";
        alpha++;
        tempRow++;
    }
}