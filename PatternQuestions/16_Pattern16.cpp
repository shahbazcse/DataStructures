#include<iostream>
using namespace std;
/*
Print the pattern given below:
            A
            BC
            DEF
            GHIJ
*/

int main(){
    int row, col, tempRow;
    cout<<"Print the no. of rows: ";
    cin>>row;
    tempRow=1;
    char alpha=65;
    while(tempRow<=row)
    {
        col=1;
        while(col<=tempRow){
            cout<<alpha;
            alpha++;
            col++;
        }
        cout<<"\n";
        tempRow++;
    }
}