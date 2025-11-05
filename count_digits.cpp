#include <bits/stdc++.h>
using namespace std;
//funtion
int count_digits(int n, int count){
    n = abs(n);
    //base case
    if(n == 0){
        if(count == 0) return 1;
    return count;
    }
    //recursive call
    return count_digits(n/10, count+1);
}

int main() {
    cout << count_digits(12345, 0);
    return 0;
}