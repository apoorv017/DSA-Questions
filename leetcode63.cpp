#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
    int n = grid.size();
    int m = grid[0].size();

    // out of bounds or obstacle
    if (i >= n || j >= m || grid[i][j] == 1) return 0;

    // destination
    if (i == n - 1 && j == m - 1) return 1;

    // memoized
    if (dp[i][j] != -1) return dp[i][j];

    int right = helper(grid, i, j + 1, dp);
    int down = helper(grid, i + 1, j, dp);

    return dp[i][j] = right + down;
}

int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper(grid, 0, 0, dp);
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

    cout << uniquePathsWithObstacles(grid) << "\n";
    return 0;
}
