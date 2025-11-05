#include <bits/stdc++.h>
using namespace std;

void reverse(string s, int i){
    if(i == s.size() ){
        return s[i];
    }
    return reverse(s, i+1, n) + s[i];
}

int main(){
    string s = "abcde";
    cout << reverse(s, 0);
    return 0;
}