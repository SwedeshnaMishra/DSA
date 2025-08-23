// 79. Word Search

// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

// Example 1:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true

// Example 2:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true

// Example 3:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false

// Constraints:
// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.

class Solution {
public:
    int ROWS, COLS;
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();
        
        unordered_map<char,int> boardCount, wordCount;
        for (auto& row : board)
            for (char ch : row) boardCount[ch]++;
        for (char ch : word) wordCount[ch]++;
        for (auto& [ch, cnt] : wordCount)
            if (boardCount[ch] < cnt) return false;

        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(board[r][c] == word[0] && dfs(board, word, r, c, 0, visited)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int i,vector<vector<bool>>& visited){
        if(i == word.size()) return true;
        if(r < 0 || c < 0 || r >= ROWS || c >= COLS || visited[r][c] || board[r][c] != word[i]) 
            return false;
        
        visited[r][c] = true;
        bool res = dfs(board, word, r+1, c, i+1, visited) ||
                   dfs(board, word, r-1, c, i+1, visited) ||
                   dfs(board, word, r, c+1, i+1, visited) ||
                   dfs(board, word, r, c-1, i+1, visited);
        visited[r][c] = false; 
        return res;
    }
};
