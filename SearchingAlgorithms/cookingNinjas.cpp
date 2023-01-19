// Link: https://www.codingninjas.com/codestudio/problems/cooking-ninjas_1164174

// Approach: Binary Search [TC: O(N)]

bool isPossible(vector<int> &rank, int m, int mid){
    int count;
    int dish=0;
    int time;
    
    for(int i=0; i<rank.size(); i++){
        count=1;
        time=0;
        while(true){
            if(time+(rank[i]*count)<=mid){
                time+=rank[i]*count;
                dish++;
                count++;
                if(dish==m) return true;
            }else break;   
        }
    }
    return false;
}

int minCookTime(vector<int> &rank, int m)
{
//     sort(rank.begin(),rank.end());
    int s=0;
    int maxi=INT_MIN;
    for(int i=0; i<rank.size(); i++){
        maxi=max(maxi,rank[i]);
    }
    int e=maxi*m*(m+1)/2;
    int mid=s+(e-s)/2;
    int ans=-1;
    
    while(s<=e){
        if(isPossible(rank,m,mid)){
            ans=mid;
            e=mid-1;
        }else s=mid+1;
        mid=s+(e-s)/2;
    }
    return ans;
}