#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return false;                    
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);                 
        bool ispos = false;
        helper(0, s, dict, memo, ispos);
        return ispos;
    }

private:
    void helper(int start, const string& s, unordered_set<string>& dict,
                vector<int>& memo, bool& ispos) {
        if (ispos) return;               // early stop if already found
        if (start == (int)s.size()) {    // reached end 
            ispos = true;
            return;
        }
        if (memo[start] == 0) return;    // already known to be impossible from here

        string cur = "";
        for (int end = start; end < (int)s.size(); ++end) {
            cur.push_back(s[end]);
            if (dict.count(cur)) {
                helper(end + 1, s, dict, memo, ispos);
                if (ispos) {
                    memo[start] = 1;
                    return;
                }
            }
        }

        memo[start] = 0; 
    }
};
