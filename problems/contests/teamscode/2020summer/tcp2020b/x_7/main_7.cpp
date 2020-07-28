#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        ans += s[i] - '0';
    }
    cout << ans << endl;
}

