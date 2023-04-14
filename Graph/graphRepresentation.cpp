// Approach 1: Using Adjacency Matrix [TC: O(Edges) / SC: O((Nodes)^2)]

#include <bits/stdc++.h>
using namespace std;

/*
Input:
    5 6 (nodes and edges)
    1 2
    1 3 
    3 4
    2 4
    2 5
    4 5
*/

int main() {
    // 'nodes' is no. of nodes and 'edges' is no. of edges in the graph, u and v are connected nodes
    int nodes,edges,u,v;
    cin >> nodes >> edges;
    
    // NxN adjacency matrix to reprsent the graph, its nodes, edges, and connection between the nodes
    int adj[nodes+1][nodes+1]={0};
    
    // connected nodes will be marked 1, otherwise marked 0
    for(int i=0; i<edges; i++){
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // we will remove this in case of directed graph as (u--->v) will be the only valid connection
    }
    
    // printing the graph representation
    for(int i=0; i<nodes+1; i++){
        for(int j=0; j<nodes+1; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}

// Approach 2: Using Adjacency Lists [TC: O(Edges) / SC: O(2*Edges)]

#include <bits/stdc++.h>
using namespace std;

/*
Input:
    5 6 (nodes and edges)
    1 2
    1 3 
    3 4
    2 4
    2 5
    4 5
*/

int main() {
    // 'nodes' is no. of nodes and 'edges' is no. of edges in the graph, u and v are connected nodes
    int nodes,edges,u,v;
    cin >> nodes >> edges;
    
    // N+1 size adjacency lists(vector) to reprsent the graph, its nodes, edges, and connection between the nodes
    vector<int> adj[nodes+1]; // list will store all the neighbours of a particular node
    
    // connected nodes will be marked 1, otherwise marked 0
    for(int i=0; i<edges; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // we will remove this in case of directed graph as (u--->v) will be the only valid connection
    }
    
    // printing the graph representation
    for(int i=0; i<nodes+1; i++){
        for(int j=0; j<adj[i].size(); j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}