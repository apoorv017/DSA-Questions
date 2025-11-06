#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void deleteMid(stack<int> &s, int size, int curr = 0) {
        // Base case
        if (curr == size / 2) {
            s.pop();
            return;
        }

        int top = s.top();
        s.pop();

        // Recurse 
        deleteMid(s, size, curr + 1);

        // Push elements back except the middle one
        s.push(top);
    }
};

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    int size = s.size();

    Solution ob;
    ob.deleteMid(s, size);

    // print remaining stack (top to bottom)
    cout << "Stack after deleting middle element:\n";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}
