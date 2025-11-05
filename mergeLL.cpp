#include <bits/stdc++.h>
using namespace std;
// merging function
vector<int> mergeRec(const vector<int>& a, const vector<int>& b, int i = 0, int j = 0) {
    //base case
    if (i == a.size()) return vector<int>(b.begin() + j, b.end());
    if (j == b.size()) return vector<int>(a.begin() + i, a.end());

    // Recursiion
    if (a[i] < b[j]) {
        vector<int> merged = mergeRec(a, b, i + 1, j);
        merged.insert(merged.begin(), a[i]);
        return merged;
    } else {
        vector<int> merged = mergeRec(a, b, i, j + 1);
        merged.insert(merged.begin(), b[j]);
        return merged;
    }
}

int main() {
    vector<int> a = {1, 3, 5};
    vector<int> b = {2, 4, 6};
    //function calling
    vector<int> merged = mergeRec(a, b);

    cout << "Merged array: ";
    for (int x : merged) cout << x << " ";
    cout << endl;
    return 0;
}
