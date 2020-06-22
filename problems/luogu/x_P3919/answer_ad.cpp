#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
#include <utility>
#include <map>
#include <list>
using namespace std;
typedef pair <int, int> pii;
#define f first
#define s second
const int maxn = 1100000;
int n;
int rt[maxn << 5], lc[maxn << 5], rc[maxn << 5], v[maxn << 5];
int cnt;

void set_n(int inn) {
    n = 1;
    while (n < inn) 
        n <<= 1;
}

void duplicate(int &id) {
    lc[++cnt] = lc[id];
    rc[cnt] = rc[id];
    id = cnt;
}

void update(int &id, int L, int R, int p, int x) {
    duplicate(id);
    if (L == R) {
        v[id] = x;
        return;
    }
    int mid = (L + R) >> 1;
    if (p <= mid) update(lc[id], L, mid, p, x);
    else update(rc[id], mid + 1, R, p, x);
}

int query(int p, int id, int L, int R) {
    if (L == R) return v[id];
    int mid = (L + R) >> 1;
    if (p <= mid) return query(p, lc[id], L, mid);
    return query(p, rc[id], mid + 1, R);
}

int main() {
    int inn, q;
    scanf("%d%d", &inn, &q);
    set_n(inn);
    for (int i = 1; i < n; i++) {
        lc[i] = i << 1;
        rc[i] = i << 1 | 1;
    }
    int mx = n + inn;
    for (int i = n; i < mx; i++) {
        scanf("%d", &v[i]);
    }
    cnt = n << 1;
    rt[0] = 1;
    int vsn, op, p, x;
    for (int i = 1; i <= q; i++) {
        scanf("%d%d%d", &vsn, &op, &p);
        rt[i] = rt[vsn];
        if (op == 1) {
            scanf("%d", &x);
            update(rt[i], 1, n, p, x);
        }
        else {
            printf("%d\n", query(p, rt[i], 1, n));
        }
    }
}

