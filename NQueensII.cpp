#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<int> colUsed(n, 0), diag1(2*n, 0), diag2(2*n, 0);
        backtrack(0, n, colUsed, diag1, diag2, count);
        return count;
    }

private:
    void backtrack(int row, int n, vector<int>& colUsed,
                   vector<int>& diag1, vector<int>& diag2, int& count) {
        // Base case: placed all queens
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; ++col) {
            // Check if it's safe to place a queen at (row, col)
            if (colUsed[col] || diag1[row + col] || diag2[row - col + n])
                continue;

            // Place queen
            colUsed[col] = diag1[row + col] = diag2[row - col + n] = 1;

            // Recurse to next row
            backtrack(row + 1, n, colUsed, diag1, diag2, count);

            // Backtrack (remove queen)
            colUsed[col] = diag1[row + col] = diag2[row - col + n] = 0;
        }
    }
};

int main() {
    Solution sol;
    int n = 4;
    cout << sol.totalNQueens(n) << endl; // Output: 2
    return 0;
}
