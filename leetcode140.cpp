#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;
        return backtrack(s, dict, 0, memo);
    }

private:
    vector<string> backtrack(string& s, unordered_set<string>& dict, int start,
                             unordered_map<int, vector<string>>& memo) {
        if (memo.count(start)) return memo[start];
        vector<string> result;

        if (start == s.size()) {
            result.push_back(""); // base case
            return result;
        }

        string word;
        for (int end = start; end < s.size(); ++end) {
            word.push_back(s[end]);

            if (dict.count(word)) {
                vector<string> sublist = backtrack(s, dict, end + 1, memo);
                for (string& sub : sublist) {
                    // combine current word with result of recursion
                    if (sub.empty()) result.push_back(word);
                    else result.push_back(word + " " + sub);
                }
            }
        }

        return memo[start] = result;
    }
};

int main() {
    Solution sol;
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};

    vector<string> ans = sol.wordBreak(s, wordDict);
    for (auto& sentence : ans) {
        cout << sentence << endl;
    }
    return 0;
}
