// alex g
#include <bits/stdc++.h>
using namespace std;
pair <int, int> a[1000000];
pair <int, int> sorted[1000000];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n-1; i++) {
        scanf("%d", &a[i].first);
        sorted[i].first = -1 * a[i].first;
        sorted[i].second = i;
    }
    sort(sorted, sorted+n-1, greater <pair <int, int> >());
    for (int i = 0; i < n-1; i++) {
        a[sorted[i].second].second = i;
    }
    int startind = n;
    int ans = 0;
    for (int i = n-2; i >= 0; i--) {
        if (a[i].second >= k-1) {
            ans += a[i].first;
        }
    }
    printf("%d\n", ans);
    for (int i = n-2; i >= 0; i--) {
        if (a[i].second < k-1) {
            printf("%d %d\n", i + 2, startind);
            startind = i + 1;
        }
    }
    cout << 1 << " " << startind << endl;
}

