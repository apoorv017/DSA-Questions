#include <bits/stdc++.h>
using namespace std;
//zero counting function
int count_zero(int n, int count){
    n = abs(n);
    if(n == 0){ //base case
        if(count == 0) return 1;
    return count;
    }
    // recursive condition based calls
    if(n % 10 == 0) return count_zero(n/10, count+1);
    else return count_zero(n/10, count);
}

int main() {
    // function call and print result
    cout << count_zero(120807, 0);
    return 0;
}