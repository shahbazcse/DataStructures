#include<iostream>
using namespace std;
/*
Print the pattern given below:
            321
            321
            321
*/

int main(){
    int row, col, tempRow;
    cout<<"Print the no. of rows: ";
    cin>>row;
    tempRow=1;
    while (tempRow<=row)
    {
        col=1;
        while(col<=row){
            cout<<row-col+1;
            col++;
        }
        cout<<"\n";
        tempRow++;
    }
    
}