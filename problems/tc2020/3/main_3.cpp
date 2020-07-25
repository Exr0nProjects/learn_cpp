#include <bits/stdc++.h>
using namespace std;
int a[100];
bool vis[100];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int t = 0, ans = 0;
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    while (a[t] != 0) {
        t += a[t];
        if (vis[t]) {
            ans = -1;
            break;
        }
        vis[t] = 1;
        if (t >= n) t = t%n;
        ans++;
    }
    cout << ans << endl;
}

