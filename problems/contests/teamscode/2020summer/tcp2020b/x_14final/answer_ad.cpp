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
const int maxn = 100010;
int n, m, a[maxn], t[maxn];//value and time
int bit1[maxn >> 1], bit2[maxn >> 1];
int la[maxn], ra[maxn], lt[maxn], rt[maxn];//temp arrays storing the value and time for each side
int ans[maxn];

int lb(int x) {
    return x & -x;
}

void modify(int bit[], int id, int v) {
    while (id < maxn >> 1) {
        bit[id] += v;
        id += lb(id);
    }
}

int query(int bit[], int id) {
    int ret = 0;
    while (id > 0) {
        ret += bit[id];
        id -= lb(id);
    }
    return ret;
}

void find_inver(int L, int R) {
    if (L == R) return;
    int mid = (L + R) >> 1;
    find_inver(L, mid);
    find_inver(mid + 1, R);
    /*printf("%d %d: ", L, R);
    for (int i = L; i < R; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");*/
    int nl = mid - L + 1, nr = R - mid;
    for (int i = 0; i < nl; i++) {
        la[i] = a[L + i];
        lt[i] = t[L + i];
        modify(bit1, lt[i], 1);
    }
    for (int i = 0; i < nr; i++) {
        ra[i] = a[mid + i + 1];
        rt[i] = t[mid + i + 1];
    }
    int i = 0, j = 0, cnt = L;
    while (i < nl && j < nr) {
        if (la[i] < ra[j]) {
            a[cnt] = la[i];
            t[cnt++] = lt[i];
            ans[lt[i]] += query(bit2, lt[i]);
            modify(bit1, lt[i], -1);
            i++;
        }
        else {
            a[cnt] = ra[j];
            t[cnt++] = rt[j];
            ans[rt[j]] += query(bit1, rt[j]);
            modify(bit2, rt[j], 1);
            j++;
        }
    }
    while (i < nl) {
        a[cnt] = la[i];
        t[cnt++] = lt[i];
        ans[lt[i]] += query(bit2, lt[i]);
        i++;
    }
    while (j < nr) {
        a[cnt] = ra[j];
        t[cnt++] = rt[j];
        ans[rt[j]] += query(bit1, rt[j]);
        j++;
    }
    //memset(bit1, 0, sizeof(bit1));
    //memset(bit2, 0, sizeof(bit2));
}

int main() {
    scanf("%d%d", &n, &m);
    map <int, int> mp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        mp[a[i]] = i;
        t[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        t[mp[x]] = m - i + 1;
    }
    find_inver(0, n - 1);
    ans[1] /= 2;
    long long v = 0;
    for (int i = 1; i <= m + 1; i++) {
        //printf("%d ", ans[i]);
        v += ans[i];
    }
    //printf("\n");
    for (int i = m + 1; i > 1; i--) {
        printf("%lld\n", v);
        v -= ans[i];
    }
}
