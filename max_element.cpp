#include <bits/stdc++.h>
using namespace std;
//function
int max_ele(vector<int> arr, int m, int i){
    int n = arr.size();
    //base case
    if(i == n-1 ){
        return m;
    }
    //recursive call
    return max_ele(arr, max(m, arr[i]), i+1);
}

int main() {

    vector<int> arr = {2, 5, 1, 8, 3};
    //function call
    cout << max_ele(arr, 0, 0);
    return 0;
}