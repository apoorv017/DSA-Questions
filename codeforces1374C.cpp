#include <bits/stdc++.h>
using namespace std;

bool isValid(const string &s) {
    int bal = 0;
    for (char c : s) {
        if (c == '(') bal++;
        else bal--;
        if (bal < 0) return false;
    }
    return bal == 0;
}

void backtrack(string s, int moves, int &ans, unordered_set<string> &visited) {
    if (isValid(s)) {
        ans = min(ans, moves);
        return;
    }

    if (moves >= ans) return;  // pruning
    if (visited.count(s)) return;
    visited.insert(s);

    int n = s.size();
    for (int i = 0; i < n; i++) {
        char c = s[i];
        string t = s;
        t.erase(t.begin() + i);

        // Move to start
        backtrack(c + t, moves + 1, ans, visited);

        // Move to end
        backtrack(t + c, moves + 1, ans, visited);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int ans = INT_MAX;
        unordered_set<string> visited;
        backtrack(s, 0, ans, visited);

        cout << ans << "\n";
    }
    return 0;
}
