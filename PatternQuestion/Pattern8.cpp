#include<iostream>
using namespace std;
/*
Print the pattern given below:
            1
            2 3
            4 5 6
            7 8 9 10
*/

int main(){
    int row, col, tempRow, count;
    cout<<"Print the no. of rows: ";
    cin>>row;
    tempRow=1;
    count=1;
    while (tempRow<=row)
    {
        col=1;
        while(col<=tempRow){
            cout<<count<<" ";
            count++;
            col++;
        }
        cout<<"\n";
        tempRow++;
    }
    
    
}