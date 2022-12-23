#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size){
    cout<<"Printing the array"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"Printing done"<<endl;
}

int getMax(int num[], int n){
    int i, max;
    max=INT_MIN;
    for ( i = 0; i < n; i++)
    {
        if(max<num[i])
            max = num[i];
    }
    return max;
}

int getMin(int num[], int n){
    int i, min;
    min=INT_MAX;
    for ( i = 0; i < n; i++)
    {
        if(min>num[i])
            min = num[i];
    }
    return min;
}

int sumOfArray(int num[], int n){
    int sum=0;
    for (int i = 0; i < 5; i++)
    {
        sum=sum+num[i];
    }
    return sum;
}

void updateArray(int arr[], int n){
    cout<<"Inside called function"<<endl;
    arr[0]=20;
    arr[1]=30;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Going back to main function"<<endl;
}

int main(){
    // // declaration
    // int arr1[15];
    // char ch[5];
    // double firstDouble[3];
    // bool firstBool[2];

    // accessing
    // cout<<arr1[0]<<endl;
    // cout<<arr1[1]<<endl;
    // cout<<arr1[2]<<endl;
    
    // // initialize
    // int arr2[3]={5,7,11};

    // cout<<arr2[0]<<endl;
    // cout<<arr2[1]<<endl;
    // cout<<arr2[2]<<endl;

    // // passing array to functions
    // printArray(arr1,15);
    // printArray(arr2,3);

    // // Maximum Value
    // cout<<"Maximum value: "<<getMax(arr2,3)<<endl;

    // //  Minimum Value
    // cout<<"Minimum value: "<<getMin(arr2,3)<<endl;

    // int arr3[3]= {1,2,3};
    // updateArray(arr3,3);

    // cout<<"Printing from main function"<<endl;
    // for (int i = 0; i < 3; i++)
    // {
    //     cout<<arr3[i]<<" ";
    // }
    // cout<<endl;

    // Sum of an Array
    int arr4[5]={2,7,1,-4,11};
    cout<<"Sum of Array elements: "<<sumOfArray(arr4,5)<<endl;
    
    return 0;
}