#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits, int i = 0, string curr = "", vector<string> res = {}) {
        if (digits.empty()) return {}; 
        //mapping 
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        // base case
        if (i == digits.size()) {
            res.push_back(curr);
            return res; }
        // get corresponding
        string letters = mapping[digits[i] - '0'];
        // recursive calls 
        vector<string> result;
        for (char c : letters) {
            vector<string> temp = letterCombinations(digits, i + 1, curr + c);
            result.insert(result.end(), temp.begin(), temp.end());
        }

        return result;
    }
};

int main() {
    Solution ob;
    string digits = "23";
    vector<string> ans = ob.letterCombinations(digits);
    cout << "Letter combinations for digits " << digits << ":\n";
    for (auto &x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
