// Link: https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

// Approach: Floyd Warshall Algorithm [TC: O(N^3) / SC: O(N^2)]

/*
    Floyd-Warshall algorithm, which is used to find the shortest paths between all pairs of vertices in a weighted graph. Here's how it works:

        1. It uses three nested loops to iterate over all possible intermediate vertices (k), source vertices (i), and destination vertices (j).

        2. For each combination of i and j, it updates the shortest path distance between i and j by considering the possibility of going through the intermediate vertex k.

        3. The line matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]) compares the current shortest path distance between i and j (stored in the matrix array) with the sum of the 
            distances from i to k and from k to j. It takes the minimum of the two values and updates the shortest path distance between i and j if the new path through k is shorter.

        4. By repeatedly updating the matrix array for all possible combinations of i, j, and k, the algorithm gradually computes the shortest path distances between all pairs of vertices in the graph.

        5. After the algorithm completes, the matrix array will contain the shortest path distances between all pairs of vertices. The value matrix[i][j] represents the shortest path distance from vertex i to vertex j.

        Note: The algorithm assumes that the graph does not contain negative cycles. If a negative cycle exists, the algorithm will not work correctly.
*/

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
                // marking nodes with 1e9 that are unreachable from i to j
	            if(matrix[i][j] == -1){
	                matrix[i][j] = 1e9;
	            }
                // marking distance from source node to itself as 0
	            if(i == j){
	                matrix[i][j] = 0;
	            }
	        }
	    }
	    
        // Floyd Warshall Algorithm
        
        // iterating over all possible intermediate vertices (k)
	    for(int k=0; k<n; k++){
            // iterating over all possible source vertices (i)
	        for(int i=0; i<n; i++){
                // iterating over all possible destination vertices (j)
	            for(int j=0; j<n; j++){
	                matrix[i][j] = min(matrix[i][j],matrix[i][k] + matrix[k][j]);
	            }
	        }
	    }
	    
	    // for detecting negative cycles in the graph
	   // for(int i=0; i<n; i++){
	   //     if(matrix[i][j] < 0){
	   //         cout<<"Has cycle";
	   //     }
	   // }
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
	            if(matrix[i][j] == 1e9){
	                matrix[i][j] = -1;
	            }
	        }
	    }
	}
};