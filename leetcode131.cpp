#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &s, int l, int r) {
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}

void backtrack(string &s, int start, vector<string> &path, vector<vector<string>> &res) {
    if (start == s.size()) {
        res.push_back(path);
        return;
    }

    for (int end = start; end < s.size(); end++) {
        if (isPalindrome(s, start, end)) {
            path.push_back(s.substr(start, end - start + 1)); // choose
            backtrack(s, end + 1, path, res);                 // explore
            path.pop_back();                                  // unchoose
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> path;
    backtrack(s, 0, path, res);
    return res;
}

int main() {
    string s = "aab";
    vector<vector<string>> result = partition(s);
    cout << "All palindrome partitions of \"" << s << "\":\n";
    for (auto &vec : result) {
        cout << "[ ";
        for (auto &str : vec) cout << str << " ";
        cout << "]\n";
    }
    return 0;
}
