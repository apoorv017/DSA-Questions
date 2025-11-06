#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> NBitBinary(int n, int ones = 0, int zeros = 0, string b = "", vector<string> res = {}) {
        // Base case
        if (n == 0) {
            res.push_back(b);
            return res;
        }
        vector<string> result;
        vector<string> temp1 = NBitBinary(n - 1, ones + 1, zeros, b + '1');
        result.insert(result.end(), temp1.begin(), temp1.end());

        if (ones > zeros) {
            vector<string> temp2 = NBitBinary(n - 1, ones, zeros + 1, b + '0');
            result.insert(result.end(), temp2.begin(), temp2.end());
        }

        return result;
    }
};

int main() {

    int n;
    cin >> n;

    Solution sol;
    vector<string> ans = sol.NBitBinary(n);
    for (const string &s : ans) {
        cout << s << '\n';
    }

    return 0;
}
