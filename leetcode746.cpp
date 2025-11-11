#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size()-1;
        vector<int> dp(n+2, -1);
        return min(helper(cost, n, dp), helper(cost, n - 1, dp));
    }
    
    int helper(vector<int>& cost, int n, vector<int>& dp){
        if(n == 0) return cost[0];
        if(n == 1) return cost[1];

        if(dp[n] != -1) return dp[n];
        int cost1 = INT_MAX, cost2 = INT_MAX;
        cost1 = min(cost1, helper(cost, n-1, dp) + cost[n]);
        cout << cost1 << endl;
        cost2 = min(cost2, helper(cost, n-2, dp) + cost[n]);
        cout << cost2 << endl;
        dp[n] = min(cost1, cost2);

        return dp[n];
    }
};
int main() {
    Solution ob;

    int n;
    cin >> n;
    if (!(std::cin >> n)) return 0; // read number of elements
    std::vector<int> cost(n);
    for (int i = 0; i < n; ++i) std::cin >> cost[i];

    std::cout << ob.minCostClimbingStairs(cost) << std::endl;
    return 0;
}

