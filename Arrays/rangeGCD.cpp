// Link: https://www.codechef.com/problems/RGCD

#include <iostream>
#include <vector>
using namespace std;

int findGCD(int a, int b){
    if(a==0) return b;
    if(b==0) return a;
    return findGCD(b,a%b);
}

int calculate(vector<int> &arr, int a, int b){
    int temp=arr[a];
    
    for(int i=a+1; i<=b; i++){
        temp=findGCD(temp,arr[i]);
    }
    return temp;
}

void mul(vector<int> &arr, int a, int b, int n){
    for(int i=a; i<=b; i++){
        arr[i]=arr[i]*n;
    }
}

int main() {
    vector<int> arr={2,4,8,16,32};
    
	int gcd = calculate(arr,1,2);
	cout<<gcd<<endl; // 4
	
// 	for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" ";
	
	mul(arr,0,1,3);
	for(int i=0; i<arr.size(); i++) cout<<arr[i]<<" "; // 6 12 8 16 32
	cout<<endl;
	
	return 0;
}