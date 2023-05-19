// Approach: Disjoint Set: By Rank / By Size [TC: O((4*Alpa) or (1)) / SC: O(N)]

#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank,parent,size;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findUltimateParent(int node){
        if(node == parent[node]) return node;
        else return parent[node] = findUltimateParent(parent[node]);
    }
    
    // Union By Rank
    void unionByRank(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        
        if(ulp_u == ulp_v) return;
        
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    // Union By Size
    void unionBySize(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        
        if(ulp_u == ulp_v) return;
        
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main() {
    DisjointSet ds(7);
    
    // Using Union By Rank
    
    // ds.unionByRank(1,2);
    // ds.unionByRank(2,3);
    // ds.unionByRank(4,5);
    // ds.unionByRank(6,7);
    // ds.unionByRank(5,6);

    // if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
    //     cout<<"Same\n";
    // }else cout<<"Not Same\n";

    // ds.unionByRank(3,7);
    
    // if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
    //     cout<<"Same\n";
    // }else cout<<"Not Same\n";
    
    // Using Union By Size
    
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
        cout<<"Same\n";
    }else cout<<"Not Same\n";

    ds.unionBySize(3,7);
    
    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
        cout<<"Same\n";
    }else cout<<"Not Same\n";

    return 0;
}