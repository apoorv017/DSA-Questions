#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
       vector<int> dp(n+1, -1);
       return helper(n, dp); 
    }
    int helper(int n, vector<int>& dp){

        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;

        if(dp[n] != -1) return dp[n];

        dp[n] = helper(n-1, dp) + helper(n-2, dp) + helper(n-3, dp);
        return dp[n];
    }
};

int main() {
    Solution ob;

    int n;
    cin >> n;
    if (!(std::cin >> n)) return 0; // read number of elements

    std::cout << ob.tribonacci(n) << std::endl;
    return 0;
}