//#include <bits/stdc++.h>
#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>
using namespace std;
#define f first
#define s second
typedef pair <int, int> pii;
const int maxn = 100010;

int n, q;
long long d[maxn], p[maxn];//d[i] = a[i] - a[i - 1], p[i] = i * d[i]

int lowbit(int x) {
    return x & -x;
}

void update(int L, int R, long long v) {
    for (int i = L; i <= n; i += lowbit(i)) {
        d[i] += v;
        p[i] += v * L;
    }
    for (int i = ++R; i <= n; i += lowbit(i)) {
        d[i] -= v;
        p[i] -= v * R;
    }
}

long long query(int L, int R) {
    long long pL = 0, pR = 0;
    for (int i = R; i > 0; i -= lowbit(i)) {
        pR += d[i];
    }
    pR *= (R + 1);
    for (int i = R; i > 0; i -= lowbit(i)) {
        pR -= p[i];
    }
    for (int i = --L; i > 0; i -= lowbit(i)) {
        pL += d[i];
    }
    pL *= (L + 1);
    for (int i = L; i > 0; i -= lowbit(i)) {
        pL -= p[i];
    }
    return pR - pL;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        update(i, i, x);
    }
    for (int i = 0; i < q; i++) {
        char op;
        int L, R;
        cin >> op;
        scanf("%d%d", &L, &R);
        if (op == 'Q') {
            printf("%lld\n", query(L, R));
        }
        if (op == 'C') {
            long long x;
            scanf("%lld", &x);
            update(L, R, x);
        }
    }
}

