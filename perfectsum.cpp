class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
        const int MOD = 1000000007;
        int n = arr.size();
        vector<int> dp(target + 1, 0);

        // base: empty subset sums to 0
        dp[0] = 1;

        // handle first element explicitly (optional, but clear)
        if (n > 0) {
            if (arr[0] == 0) {
                // zero doubles ways to make sum 0
                dp[0] = 2;
            } else if (arr[0] <= target) {
                dp[arr[0]] = (dp[arr[0]] + 1) % MOD;
            }
        }

        // process remaining elements
        for (int i = 1; i < n; ++i) {
            int val = arr[i];
            // iterate sums from target down to 0 to avoid reusing the same element
            for (int s = target; s >= 0; --s) {
                if (val <= s) {
                    dp[s] = (dp[s] + dp[s - val]) % MOD;
                }
                // if val == 0, the above reduces to dp[s] += dp[s], which doubles dp[s] as required
            }
        }

        return dp[target];
    }
};
