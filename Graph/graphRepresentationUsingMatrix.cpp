#include <iostream>
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
    // nodes is no. of nodes and edges is no. of edges in the graph
    int nodes,edges,u,v;
    cin >> nodes >> edges;
    
    // NxN adjacent matrix to reprsent the graph, its nodes, edges, and connection between the nodes
    int adj[nodes+1][nodes+1]={0};
    
    // connected nodes will be marked 1, otherwise marked 0
    for(int i=0; i<edges; i++){
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
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