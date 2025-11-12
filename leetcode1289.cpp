#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
    int n = grid.size();
    int m = grid[0].size();

    // base case: last row
    if (i == n - 1) return grid[i][j];

    // memoized
    if (dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    for (int k = 0; k < m; ++k) {
        if (k == j) continue; // can't use same column
        ans = min(ans, grid[i][j] + helper(grid, i + 1, k, dp));
    }

    return dp[i][j] = ans;
}

int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int ans = INT_MAX;
    for (int j = 0; j < m; ++j) {
        ans = min(ans, helper(grid, 0, j, dp));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];

    cout << minFallingPathSum(grid) << "\n";
    return 0;
}
