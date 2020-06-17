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
int n, mc;
int set_t[maxn << 1];
int c[maxn << 1];//bit map all colors
void set_n(int inn) {
    n = 1;
    while (n < inn) 
        n <<= 1;
}

void push_down(int id) {
    if (set_t[id]) {
        int lc = id << 1, rc = id << 1 | 1;
        set_t[lc] = set_t[rc] = set_t[id];
        c[lc] = c[rc] = 1 << set_t[id];
        set_t[id] = 0;
    }
}

void update(int id) {
    int lc = id << 1, rc = id << 1 | 1;
    c[id] = c[lc] | c[rc];
}

void modify_helper(int qL, int qR, int qv, int L, int R, int id) {
    if (L > R) return;
    if (L > qR || R < qL) return;
    if (qL <= L && R <= qR) {
        set_t[id] = qv;
        c[id] = 1 << qv;
        return;
    }
    push_down(id);
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
        return c[id];
    }
    push_down(id);
    int lc = id << 1, rc = id << 1 | 1, mid = L + R >> 1;
    return query_helper(qL, qR, L, mid, lc) | query_helper(qL, qR, mid + 1, R, rc);
}

int query(int L, int R) {
    return query_helper(L, R, 1, n, 1);
}

int main() {
    int inn, q;
    scanf("%d%d%d", &inn, &mc, &q);
    set_n(inn);
    modify(1, inn, 1);
    for (int i = 0; i < q; i++) {
        char op;
        int L, R;
        scanf(" %c%d%d", &op, &L, &R);
        if (L > R) swap(L, R);
        if (op == 'C') {
            int x;
            scanf("%d", &x);
            modify(L, R, x);
        }
        if (op == 'P') {
            int ans = query(L, R);
            int cnt = 0;
            for (int i = 1; i <= mc; i++) {
                if (ans & (1 << i)) cnt++;
            }
            printf("%d\n", cnt);
        }
    }
}

