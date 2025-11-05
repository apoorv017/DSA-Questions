#include <bits/stdc++.h>
using namespace std;
//check sorting function
bool check_sort(vector<int> arr, int i){
    int n = arr.size();
    //base case
    if(i == n-1 || arr.size() == 0){
        return true;
    }
    if(arr[i] > arr[i+1]) return false;
    //recursive call
    return check_sort(arr, i+1);
}

int main() {

    vector<int> arr = {};
    //function call and printing result
    if (check_sort(arr, 0)) {cout << "True";}
    else {cout << "False";}
    return 0;
}