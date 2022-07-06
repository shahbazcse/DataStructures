#include<iostream>
using namespace std;

int reverse(int num[], int size){
    int temp;
    int end=size-1;
    for (int start = 0; start <= end; start++)
    {
        temp=num[start];
        num[start]=num[end];
        num[end]=temp;
        end--;
    }
    return 0;
}
int main(){
    int arr[5]={1,2,3,4,5};
    cout<<"Before: "<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    reverse(arr,5);
    cout<<"After: "<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}