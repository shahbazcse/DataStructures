#include<iostream>
using namespace std;

int main(){
    int arr[7]={2,3,4,2,3,6,4};
    int unique=0;
    int arrSize=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<=arrSize-1; i++){
        unique=unique^arr[i];
    }
    cout<<"Unique no. is : "<<unique<<endl;
}