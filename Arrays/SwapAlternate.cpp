#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void swapAlternate(int num[], int size){
        for(int i=0; i<size; i=i+2){
            int j=i+1;
            if(j<size){
                int temp=num[i];
                num[i]=num[j];
                num[j]=temp;
            }
        }
}

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int even[6]={1,2,3,4,5,6};
    int odd[5]={10,20,30,40,50};
    swapAlternate(even,6);
    printArray(even,6);
    swapAlternate(odd,5);
    printArray(odd,5);
    cout<<"Working!"<<endl;
}