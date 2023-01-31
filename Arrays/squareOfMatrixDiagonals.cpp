// Link: https://www.geeksforgeeks.org/squares-of-matrix-diagonal-elements/

// Approach: [TC: O(N^2)]

void diagonalsquare(int mat[][MAX], int row,int column){
	cout << "Diagonal one : ";
	for(int i=0; i<row; i++){
      for(int j=0; j<column; j++){
      		if(i==j) cout<<mat[i][j]*mat[i][j]<<" ";
      }
    }

	cout << " \nDiagonal two : ";
	for(int i=0; i<row; i++){
		for(int j=0; j<column; j++){
        	if(i+j==column-1) cout<<mat[i][j]*mat[i][j]<<" ";
        }    
    }
}