// alex, 4
#include <bits/stdc++.h>
using namespace std;
bool notprime[101000];
int main() {
    int n;
    cin >> n;
    memset(notprime, 0, sizeof(notprime));
    notprime[0] = 1;
    notprime[1] = 1;
    for (int i = 2; i < 100000; i++) {
        if (!notprime[i]) {
            for (int j = i * 2; j < 100000; j += i) {
                notprime[j] = 1;
            }
        }
    }
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (notprime[x]) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}

