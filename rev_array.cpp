#include <bits/stdc++.h>
using namespace std;
//function that returns a vector
vector<int> reverse(vector<int> arr, vector<int> rev, int i){
    if(i== arr.size()) return rev; //base case
    rev = reverse(arr,rev, i + 1);  // recursive call
    rev.push_back(arr[i]); //insertion
    return rev; //returning vector that us reversed
}

int main() {
    vector<int> arr = {1,2,3,4,5};
    vector<int> rev = {};
    rev = reverse(arr,rev, 0); //function call
    for(int j: rev){
        cout << j << " ";
    }
    return 0;
}