#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 20010;

int n = 131072, bit[140000], c[maxn], d[maxn];
pair <int, int> srt[maxn];

int low_bit(int x) {
    return x & (-x);
}

void update(int idx) {
    if (idx == n) return;
    bit[idx]++;
    update(idx + low_bit(idx));
}

int query(int idx) {
    if (idx == 0) return 0;
    return bit[idx] + query(idx - low_bit(idx));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(bit, 0, sizeof(bit));
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));
        int inn;
        scanf("%d", &inn);
        for (int i = 0; i < inn; i++) {
            int x;
            scanf("%d", &x);
            srt[i] = {x, i};
            c[i] = query(x - 1);
            update(x);
        }
        sort(srt, srt + inn);
        long long ans = 0;
        for (int i = 0; i < inn; i++) {
            int id = srt[i].second;
            d[id] = i - c[id];
            ans += c[id] * (inn - id - 1 - d[id]) + (id - c[id]) * d[id];
        }
        printf("%lld\n", ans);
    }
}

