// Link: https://practice.geeksforgeeks.org/problems/word-search/1

// Approach: Recursion + Hashing [TC: O(N*M*(4^L)) / SC: O(L)]
// L is size of word

class Solution {
public:
    bool search(vector<vector<char>> &board, string word, int i, int j, int idx){
        // check if complete word is found
        if(idx == word.size()) return true;

        // check if search space is within board range
        if(i == board.size() || j == board[0].size() || i < 0 || j < 0 || board[i][j] != word[idx]) return false;
        
        // mark character as visited using hashing
        board[i][j] = '#';
        
        bool path1 = search(board,word,i,j+1,idx+1);
        bool path2 = search(board,word,i,j-1,idx+1);
        bool path3 = search(board,word,i+1,j,idx+1);
        bool path4 = search(board,word,i-1,j,idx+1);
        
        // unmark character visited status after backtracking
        board[i][j] = word[idx];
        
        // check if single character of the word is found
        if(path1 || path2 || path3 || path4) return true;
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {

        // check for every character in the board
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                    // check if character in board and character in word string is found
                    if(search(board,word,i,j,0)) return true;
                }
            }
        }
        // return false if word is not found
        return false;
    }
};