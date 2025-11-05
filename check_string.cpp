#include <bits/stdc++.h>
using namespace std;
//check function
bool check_sort(string s, int i, int n){
    //base case
    if(i == n-1){
        return true;
    }
    // recurive call if digit is found true
    if(isdigit(s[i])) return check_sort(s, i+1, n);
    return false;
}

int main() {

    string s = "";
    int n = s.size();
    //function call and printing result
    if (check_sort(s, 0, n)) {cout << "True";}
    else {cout << "False";}
    return 0;
}