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
#define int long long
#define f first
#define s second
const int maxn = 140000, md = 10007;
int n;
int add_t[maxn << 1], mul_t[maxn << 1], set_t[maxn << 1];
//addition, set, and multiplication tags
long long sum[maxn << 1], sum_s[maxn << 1], sum_c[maxn << 1];
//sum, sum of squares, and sum of cubes

void set_n(int inn) {
    n = 1;
    while (n < inn) 
        n <<= 1;
}

void MOD(int id) {
    add_t[id] %= md;
    mul_t[id] %= md;
    set_t[id] %= md;
    sum[id] %= md;
    sum_s[id] %= md;
    sum_c[id] %= md;
}

void tag(int id, int len, int s, int m, int a) {
    if (s != -1) {
        add_t[id] = 0;
        mul_t[id] = 1;
        set_t[id] = s;
        sum[id] = set_t[id] * len;
        sum_s[id] = set_t[id] * set_t[id] * len;
        sum_c[id] = set_t[id] * set_t[id] * set_t[id] * len;
        sum[id] %= md;
        sum_s[id] %= md;
        sum_c[id] %= md;
        return;
    }
    if (set_t[id] != -1) {
        set_t[id] *= m;
        set_t[id] += a;
        set_t[id] %= md;
        sum[id] = set_t[id] * len;
        sum_s[id] = set_t[id] * set_t[id] * len;
        sum_c[id] = set_t[id] * set_t[id] * set_t[id] * len;
        sum[id] %= md;
        sum_s[id] %= md;
        sum_c[id] %= md;
    }
    else {
        mul_t[id] *= m;
        add_t[id] = m * add_t[id] + a;
        sum_c[id] *= m * m * m;
        sum_s[id] *= m * m;
        sum[id] *= m;
        sum_c[id] %= md;
        sum_c[id] += 3 * a * sum_s[id] + 3 * a * a * sum[id] + a * a * a * len;
        sum_s[id] += 2 * a * sum[id] + a * a * len;
        sum[id] += a * len;
        MOD(id);
    }
}

void update(int id) {
    int lc = id << 1, rc = id << 1 | 1;
    sum[id] = sum[lc] + sum[rc];
    sum_s[id] = sum_s[lc] + sum_s[rc];
    sum_c[id] = sum_c[lc] + sum_c[rc];
    sum[id] %= md;
    sum_s[id] %= md;
    sum_c[id] %= md;
}

void push_down(int id, int L, int R) {
    int mid = L + R >> 1;
    tag(id << 1, mid - L + 1, set_t[id], mul_t[id], add_t[id]);
    tag(id << 1 | 1, R - mid, set_t[id], mul_t[id], add_t[id]);
    set_t[id] = -1;
    add_t[id] = 0;
    mul_t[id] = 1;
}

void modify(int qL, int qR, int tp, int qv, int L, int R, int id) {
    //left and right for modify, tp of modify, value of modify, current left, right, and id
    if (L > R) return;
    if (qR < L || R < qL) return;
    if (qL <= L && R <= qR) {
        if (tp == 1) {
            tag(id, R - L + 1, -1, 1, qv);
        }
        if (tp == 2) {
            tag(id, R - L + 1, -1, qv, 0);
        }
        if (tp == 3) {
            tag(id, R - L + 1, qv, 1, 0);
        }
        return;
    }
    int lc = id << 1, rc = id << 1 | 1, mid = R + L >> 1;
    push_down(id, L, R);
    modify(qL, qR, tp, qv, L, mid, lc);
    modify(qL, qR, tp, qv, mid + 1, R, rc);
    update(id);
}

int query(int qL, int qR, int p, int L, int R, int id) {
    if (L > R) return 0;
    if (qR < L || R < qL) return 0;
    if (qL <= L && R <= qR) {
        if (p == 1) return sum[id];
        if (p == 2) return sum_s[id];
        if (p == 3) return sum_c[id];
    }
    int lc = id << 1, rc = id << 1 | 1, mid = R + L >> 1;
    push_down(id, L, R);
    return (query(qL, qR, p, L, mid, lc) + query(qL, qR, p, mid + 1, R, rc)) % md;
}

signed main() {
    int inn, q;
    while (scanf("%lld%lld", &inn, &q) == 2) {
        if (inn == 0 && q == 0) break;
        set_n(inn);
        for (int i = 1; i <= n << 1; i++) {
            mul_t[i] = 1;
            set_t[i] = -1;
        }
        memset(sum, 0, sizeof(sum));
        memset(sum_s, 0, sizeof(sum_s));
        memset(sum_c, 0, sizeof(sum_c));
        memset(add_t, 0, sizeof(add_t));
        int op, L, R, x;
        while (q--) {
            scanf("%lld%lld%lld%lld", &op, &L, &R, &x);
            if (op == 1) {//add to range
                modify(L, R, 1, x, 1, n, 1);
            }
            if (op == 2) {//multiply to range
                modify(L, R, 2, x, 1, n, 1);
            }
            if (op == 3) {//set in range
                modify(L, R, 3, x, 1, n, 1);
            }
            if (op == 4) {//query
                printf("%lld\n", query(L, R, x, 1, n, 1));
            }
            if (op == 5) {
                for (int i = 1; i <= inn; i++) {
                    printf("%lld ", query(i, i, 1, 1, n, 1));
                }
                printf("\n");
                for (int i = 1; i <= inn; i++) {
                    printf("%lld ", query(i, i, 2, 1, n, 1));
                }
                printf("\n");
                for (int i = 1; i <= inn; i++) {
                    printf("%lld ", query(i, i, 3, 1, n, 1));
                }
                printf("\n");
            }
        }
    }
}

