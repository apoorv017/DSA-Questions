#include <bits/stdc++.h>
using namespace std;

void backtrack(int n, int row, vector<bool> &cols, vector<bool> &diag1, vector<bool> &diag2, int &count) {
    if (row == n) {
        count++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (cols[col] || diag1[row + col] || diag2[row - col + n - 1]) continue;

        cols[col] = diag1[row + col] = diag2[row - col + n - 1] = true;
        backtrack(n, row + 1, cols, diag1, diag2, count);
        cols[col] = diag1[row + col] = diag2[row - col + n - 1] = false;
    }
}

int totalNQueens(int n) {
    int count = 0;
    vector<bool> cols(n, false);
    vector<bool> diag1(2 * n, false);
    vector<bool> diag2(2 * n, false);
    backtrack(n, 0, cols, diag1, diag2, count);
    return count;
}

int main() {
    int n = 4;
    cout << "Number of distinct solutions for " << n << "-Queens: "
         << totalNQueens(n) << endl;
    return 0;
}
