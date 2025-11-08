#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int> &nums, vector<int> &path, vector<vector<int>> &res, vector<bool> &used) {
    if (path.size() == nums.size()) {
        res.push_back(path);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue; // skip duplicates

        used[i] = true;
        path.push_back(nums[i]);
        backtrack(nums, path, res, used);
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());
    backtrack(nums, path, res, used);
    return res;
}

int main() {
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> result = permuteUnique(nums);
    cout << "Unique permutations:\n";
    for (auto &perm : result) {
        cout << "[ ";
        for (int x : perm) cout << x << " ";
        cout << "]\n";
    }
    return 0;
}
