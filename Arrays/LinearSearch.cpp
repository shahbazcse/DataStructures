#include<iostream>
using namespace std;

bool search(int num[], int size, int key){
    for (int i = 0; i < size; i++)
    {
        if(num[i]==key)
            return true;
        else
            return false;
    }
}

int main(){
    int arr[10]={5,7,-2,10,22,-2,0,5,22,1};
    cout<<"Enter the key: ";
    int key=0;
    cin>>key;
    bool found = search(arr,10,key);
    if(found)
        cout<<"Key is found"<<endl;
    else
        cout<<"Key is not found"<<endl;
    return 0;
}