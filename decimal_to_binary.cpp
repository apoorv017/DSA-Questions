#include <bits/stdc++.h>
using namespace std;
//function
int dec_to_bi(int n){
    if (n == 0) return 0; //base case
    return 10*(dec_to_bi(n/2)) + (n%2); //recursive call
}

int main() {
    cout << dec_to_bi(10); //function call and binary result
    return 0;
}