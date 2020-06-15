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
const int maxn = 140000;
int n;
int sum[maxn << 1], set_t[maxn << 1];
void set_n(int inn) {
    n = 1;
    while (n < inn) 
        n <<= 1;
}

void push_down(int L, int R, int id) {
    if (set_t[id]) {
        int lc = id << 1, rc = id << 1 | 1, mid = L + R >> 1;
        set_t[lc] = set_t[rc] = set_t[id];
        sum[lc] = (mid - L + 1) * set_t[lc];
        sum[rc] = (R - mid) * set_t[rc];
        set_t[id] = 0;
    }
}

void update(int id) {
    int lc = id << 1, rc = id << 1 | 1;
    sum[id] = sum[lc] + sum[rc];
}

void modify_helper(int qL, int qR, int qv, int L, int R, int id) {
    if (L > R) return;
    if (L > qR || R < qL) return;
    if (qL <= L && R <= qR) {
        set_t[id] = qv;
        sum[id] = (R - L + 1) * qv;
        return;
    }
    push_down(L, R, id);
    int lc = id << 1, rc = id << 1 | 1, mid = L + R >> 1;
    modify_helper(qL, qR, qv, L, mid, lc);
    modify_helper(qL, qR, qv, mid + 1, R, rc);
    update(id);
}

void modify(int L, int R, int v) {
    modify_helper(L, R, v, 1, n, 1);
}

int query_helper(int qL, int qR, int L, int R, int id) {
    if (L > R) return 0;
    if (L > qR || R < qL) return 0;
    if (qL <= L && R <= qR) {
        return sum[id];
    }
    push_down(L, R, id);
    int lc = id << 1, rc = id << 1 | 1, mid = L + R >> 1;
    return query_helper(qL, qR, L, mid, lc) + query_helper(qL, qR, mid + 1, R, rc);
}

int query(int L, int R) {
    return query_helper(L, R, 1, n, 1);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int c = 0; c < t; c++) {
        memset(sum, 0, sizeof(sum));
        memset(set_t, 0, sizeof(set_t));
        int inn, q;
        scanf("%d%d", &inn, &q);
        set_n(inn);
        modify(1, inn, 1);
        for (int i = 0; i < q; i++) {
            int L, R, x;
            scanf("%d%d%d", &L, &R, &x);
            modify(L, R, x);
        }
        printf("Case %d: The total value of the hook is %d.\n", c + 1, query(1, inn));
    }
}

