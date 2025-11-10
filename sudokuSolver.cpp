class Solution {
public:
    void solveSudoku(vector<vector<char>>& board, int i = 0, int j = 0) {
        if (i == 9) return; // solved 

        // move to next row if end of column
        if (j == 9) {
            solveSudoku(board, i + 1, 0);
            return;
        }

        // skip
        if (board[i][j] != '.') {
            solveSudoku(board, i, j + 1);
            return;
        }

        for (char ch = '1'; ch <= '9'; ch++) {
            if (isValid(board, i, j, ch)) {
                board[i][j] = ch;
                solveSudoku(board, i, j + 1);
                if (isComplete(board)) return; // stop 
                board[i][j] = '.'; // backtrack
            }
        }
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for (int x = 0; x < 9; x++) {
            if (board[row][x] == ch) return false;
            if (board[x][col] == ch) return false;
            int r = 3 * (row / 3) + x / 3;
            int c = 3 * (col / 3) + x % 3;
            if (board[r][c] == ch) return false;
        }
        return true;
    }

    bool isComplete(vector<vector<char>>& board) {
        for (auto& row : board)
            for (auto& c : row)
                if (c == '.') return false;
        return true;
    }
};
