#include<iostream>
using namespace std;
/*
Print the pattern given below:
            ABC
            BCD
            CDE
*/

int main(){
    int row, col, tempRow;
    cout<<"Print the no. of rows: ";
    cin>>row;
    tempRow=1;
    char alpha;
    while (tempRow<=row)
    {
        col=1;
        while(col<=row){
            alpha='A'+tempRow+col-2;
            cout<<alpha;
            col++;
        }
        cout<<"\n";
        tempRow++;
    }  
}