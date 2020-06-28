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
const int maxn = 50050, maxm = 10100;
int n, m, tag;
int a[maxn];
pair <pii, int> q[maxn];
map <int, int> mp;
int rev[maxn + maxm];
struct node {
    int lc, rc, sum;
};
int rt1[maxn], cnt, rt2[maxn];
node t[maxn * 45];

void duplicate(int &id) {
    t[++cnt].lc = t[id].lc;
    t[cnt].rc = t[id].rc;
    t[cnt].sum = t[id].sum;
    id = cnt;
}

void update(int id) {
    t[id].sum = t[t[id].lc].sum + t[t[id].rc].sum;
}

void modify1(int &id, int p, int L, int R) {
    if (p < L || p > R) return;
    duplicate(id);
    if (L == R) {
        t[id].sum++;
        return;
    }
    int mid = (L + R) >> 1;
    modify1(t[id].lc, p, L, mid);
    modify1(t[id].rc, p, mid + 1, R);
    update(id);
}

int lb (int x) {
    return x & -x;
}

void modify2(int &id, int p, int v, int L, int R) {
    if (p < L || p > R) return;
    if (id == 0) duplicate(id);
    if (L == R) {
        t[id].sum += v;
        return;
    }
    int mid = (L + R) >> 1;
    modify2(t[id].lc, p, v, L, mid);
    modify2(t[id].rc, p, v, mid + 1, R);
    update(id);
}

int query2(int id, int qL, int qR, int L, int R) {
    if (L > qR || R < qL) return 0;
    if (qL <= L && R <= qR) return t[id].sum;
    int mid = (L + R) >> 1;
    return query2(t[id].lc, qL, qR, L, mid) + query2(t[id].rc, qL, qR, mid + 1, R);
}

int query(int li1, int ri1, int rtl, int rtr, int L, int R, int k) {
    if (L == R) return L;
    int lv1 = t[t[li1].lc].sum, rv1 = t[t[ri1].lc].sum;
    int lv2 = 0, rv2 = 0;
    int mid = (L + R) >> 1;
    for (int i = rtl; i > 0; i -= lb(i)) {
        lv2 += query2(rt2[i], L, mid, 1, tag);
    }
    for (int i = rtr; i > 0; i -= lb(i)) {
        rv2 += query2(rt2[i], L, mid, 1, tag);
    }
    //printf("%d %d %d %d\n", lv1, rv1, lv2, rv2);
    if (rv1 - lv1 + rv2 - lv2 >= k) return query(t[li1].lc, t[ri1].lc, rtl, rtr, L, mid, k);
    else return query(t[li1].rc, t[ri1].rc, rtl, rtr, mid + 1, R, k - (rv1 - lv1 + rv2 - lv2));
}

int main() {
    int c;
    scanf("%d", &c);
    while (c--) {
        memset(t, 0, sizeof(t));
        memset(rt1, 0, sizeof(rt1));
        memset(rt2, 0, sizeof(rt2));
        cnt = 0;
        mp.clear();
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            mp[a[i]] = 0;
        }
        for (int i = 1; i <= m; i++) {
            char op;
            scanf(" %c%d%d", &op, &q[i].f.f, &q[i].f.s);
            if (op == 'Q') scanf("%d", &q[i].s);
            else {
                q[i].s = -1;
                mp[q[i].f.s] = 0;
            }
        }
        tag = 0;
        for (map <int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            it->s = ++tag;
            rev[tag] = it->f;
        }
        for (int i = 1; i <= n; i++) {
            rt1[i] = rt1[i - 1];
            modify1(rt1[i], mp[a[i]], 1, tag);
        }
        for (int i = 1; i <= m; i++) {
            if (q[i].s == -1) {
                for (int j = q[i].f.f; j <= n; j += lb(j)) {
                    modify2(rt2[j], mp[a[q[i].f.f]], -1, 1, tag);
                    modify2(rt2[j], mp[q[i].f.s], 1, 1, tag);
                }
                a[q[i].f.f] = q[i].f.s;
            }
            else {
                int L = q[i].f.f, R = q[i].f.s, k = q[i].s;
                printf("%d\n", rev[query(rt1[L - 1], rt1[R], L - 1, R, 1, tag, k)]);
            }
        }
    }
}

