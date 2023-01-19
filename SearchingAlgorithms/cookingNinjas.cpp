// Link: https://www.codingninjas.com/codestudio/problems/cooking-ninjas_1164174

// Approach: Binary Search [TC: O(N)]

bool isPossible(vector<int> &rank, int m, int mid){
    int totalDish=0; // Total dish count
    
    for(int i=0; i<rank.size(); i++){
        int chefDishCount=0; // ith chef dish count
        int time=0; // time taken by ith chef
        int j=1;
        while(time+(rank[i]*j)<=mid){
            time+=rank[i]*j;
            chefDishCount++;
            j++;
        }
        totalDish+=chefDishCount;
    }
    // Check if chefs were able to cook total dishes or not
    if(totalDish>=m) return true;
    else return false;
}

int minCookTime(vector<int> &rank, int m)
{
    sort(rank.begin(),rank.end());
    
    int s=0; // Starting time
    
    int totalTime=0;
    
    int slowestCook=rank[rank.size()-1];
    
    // Time taken by the slowest cook with maximum rank to cook all dishes will be the maximum time or end of search space
    for(int i=1; i<=m; i++) totalTime+=slowestCook*i;
    
    int e=totalTime; // Ending time/ Maximum time
    
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