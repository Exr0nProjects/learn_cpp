#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, q;
int d[maxn], p[maxn];//BIT, d[i] = a[i] - a[i - 1], p[i] = i * d[i]
int lowbit(int x) {
    return x & -x;
}
int prefix_d(int id) {//prefix sum for d
    int ans = 0;
    while (id > 0) {
        ans += d[id];
        id -= lowbit(id);
    }
    return ans;
}
int prefix_p(int id) {//prefix sum for p
    int ans = 0;
    while (id > 0) {
        ans += p[id];
        id -= lowbit(id);
    }
    return ans;
}
int query(int L, int R) {
    int pL, pR;//prefix sum for L and R
    L--;
    pL = (L + 1) * prefix_d(L) - prefix_p(L);
    pR = (R + 1)  * prefix_d(R) - prefix_p(R);
    return pR - pL;
}
void update_d(int id, int v) {
    while (id <= n) {
        d[id] += v;
        id += lowbit(id);
    }
}
void update_p(int id, int v) {
    while (id <= n) {
        p[id] += v;
        id += lowbit(id);
    }
}
void update(int L, int R, int v) {
    update_d(L, v);
    update_d(R + 1, -v);
    update_p(L, L * v);
    update_p(R + 1, (R + 1) * -v);
}
int main () {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        update(i, i, x);
    }
    for (int i = 0; i < q; i++) {
        int op, L, R;
        scanf("%d%d%d", &op, &L, &R);
        if (op == 0) {//query sum [L, R]
            printf("%d\n", query(L, R));
        }
        if (op == 1) {//add x to [L, R]
            int x;
            scanf("%d", &x);
            update(L, R, x);
        }
    }
}

