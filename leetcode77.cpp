#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k, int start = 1, vector<int> curr = {}, vector<vector<int>> res = {}) {
        // Base case
        if (curr.size() == k) {
            res.push_back(curr);
            return res;
        }

        vector<vector<int>> result;
        for (int i = start; i <= n; i++) {
            curr.push_back(i);
            // Recurse 
            vector<vector<int>> temp = combine(n, k, i + 1, curr);
            result.insert(result.end(), temp.begin(), temp.end());
            curr.pop_back(); // backtrack
        }

        return result;
    }
};

int main() {
    Solution ob;
    int n = 4, k = 2;
    vector<vector<int>> ans = ob.combine(n, k);
    cout << "Combinations of " << k << " numbers from 1 to " << n << ":\n";
    for (auto &v : ans) {
        cout << "[ ";
        for (int x : v) cout << x << " ";
        cout << "]\n";
    }
    return 0;
}
