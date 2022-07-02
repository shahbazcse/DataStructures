#include<iostream>
using namespace std;
/*
Print the pattern given below:
               1
              22 
             333
            4444
*/

int main(){
    int row, col, tempRow;
    cout<<"Print the no. of rows: ";
    cin>>row;
    tempRow=1;
    while (tempRow<=row)
    {
        int space=row-tempRow;
        while(space>0){
            cout<<" ";
            space--;
        }
        col=1;
        while(col<=tempRow){
            cout<<tempRow;
            col++;
        }
        cout<<"\n";
        tempRow++;
    }
}