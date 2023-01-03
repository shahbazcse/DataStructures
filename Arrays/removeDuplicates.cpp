// Link: https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1

class Solution{
public:
    int remove_duplicate(int a[],int n){
        int x=0;
        for(int i=0; i<n; i++){
            if(a[i]!=a[i+1] && i+1<n){
                a[x]=a[i];
                x++;
            }
        }
        
        a[x]=a[n-1];
        
        return x+1;
    }
};