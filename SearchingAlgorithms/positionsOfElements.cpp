// Link: https://www.codingninjas.com/codestudio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int first=-1;
    int last=-1;
    int i=0;
    for(i=0; i<n; i++){
        if(arr[i]==k){
            first=i;
            break;
        }
    }
    for(int j=n-1; j>=i; j--){
        if(arr[j]==k){
            last=j;
            break; 
        }
    }
    return {first, last};
}