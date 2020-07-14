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
typedef unsigned short int sint;
const int maxn = 4000010, maxm = 40010;
int n;
sint st[maxn][23];
int lg[maxn];
long long ans[maxm];

void set_lg() {
    for (int i = 2; i < maxn; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
}

sint gcd(sint a, sint b) {
    if (b > a) swap(a, b);
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

sint query(int a, int b) {
    //printf("herm %d, %d -> %d\n", b, a, b-a+1); fflush(stdout);
    //int d = lg[b - a +1];
    int d = log2(b-a+1);
    //printf("herm\n"); fflush(stdout);
    return gcd(st[a][d], st[b - (1 << d) + 1][d]);
}

int main() {
    while (scanf("%d", &n) == 1) {
        memset(st, 0, sizeof(st));
        memset(lg, 0, sizeof(lg));
        memset(ans, 0, sizeof(ans));
        set_lg();
        for (int i = 0; i < n; i++) {
            scanf("%hu", &st[i][0]);
        }
        for (int j = 1; j < 23; j++) {
            for (int i = 0; i < n; i++) {
                if (i + (1 << j) - 1 >= n) break;
                st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            sint g = st[i][0];
            int j = i;
            while (j < n) {
                int L = j, R = n;
                while (R - L > 1) {
                    int mid = (L + R) >> 1;
                    if (query(i, mid) != g) R = mid;
                    else L = mid;
                }
                ans[g] += L - j + 1;
                j = L + 1;
                g = query(i, j);
            }
        }
        int q;
        scanf("%d", &q);
        for (int i = 0; i < q; i++) {
            int x;
            scanf("%d", &x);
            printf("%lld\n", ans[x]);
        }
    }
}

