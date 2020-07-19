#include <bits/stdc++.h>
using namespace std;
int a[1010], b[1010], ans[1010];
int main() {
    string s, s1;
    cin >> s >> s1;
    int n = s.length();
    int m = s1.length();
    if (s == "0" && s1 == "0") {
        cout << 0 << endl;
        return 0;
    }
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    if (n < m) {
        while (s.length() < s1.length()) {
            s = '0' + s;
        }
        n = m;
    } else if (m < n) {
        while (s1.length() < s.length()) {
            s1 = '0' + s1;
        }
        m = n;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = s[i-1] - '0';
    }
    for (int i = 1; i <= m; i++) {
        b[i] = s1[i-1] - '0';
    }
    int j = m;
    int carry = 0;
    for (int i = n; i >= 0; i--) {
        int c = a[i] + b[j] + carry;
        if (c >= 10) {
            carry = 1;
        } else {
            carry = 0;
        }
        ans[i] = c % 10;
        j--;
    }
    int first = 1;
    for (int i = 0; i <= max(n, m); i++) {
        if (first && ans[i] == 0) continue;
        first = 0;
        cout << ans[i];
    }
    cout << endl;
}

