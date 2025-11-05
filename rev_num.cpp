#include <bits/stdc++.h>
using namespace std;
//function of digit reversal
int reverse(int n, int rev = 0){
    if (n == 0) return rev; //base case
    return reverse(n/10, rev*10 + n%10); //recursive call
}

int main() {
    cout << reverse(12345); //function call
    return 0;
}