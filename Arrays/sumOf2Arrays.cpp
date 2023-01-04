// Link: https://www.codingninjas.com/codestudio/problems/sum-of-two-arrays_893186

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	int sum1=0;
    int sum2=0;
    
    // First array
    for(int i=0; i<n; i++){
        sum1+=a[i]*pow(10,n-i-1);
    }
    for(int i=0; i<m; i++){
        sum2+=b[i]*pow(10,m-i-1);
    }
    sum1=sum1+sum2;
    vector<int> ds;
    while(sum1!=0){
        int temp=sum1%10;
        ds.push_back(temp);
        sum1=sum1/10;
    }
    reverse(ds.begin(),ds.end());
    return ds;
}