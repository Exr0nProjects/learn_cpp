// 6, alex g
#include <bits/stdc++.h>
using namespace std;
bool ispalindrome(int n) {
    string s = "";
    int temp = n;
    while (temp != 0) {
        s = char (temp%10 + '0') + s;
        temp /= 10;
    }
    for (int i = 0; i <= (s.length()-1)/2; i++) {
        if (s[i] != s[s.length()-1-i]) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (ispalindrome(i)) cout << i << endl;
    }
}

