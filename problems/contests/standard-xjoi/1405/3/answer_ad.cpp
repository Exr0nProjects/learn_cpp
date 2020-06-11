#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

int n, q;
int all[maxn], st[maxn];//BIT, first is both start and end, second is just start

int lowbit(int x) {
    return x & -x;
}

void update(int L, int R) {
    for (int i = L; i <= n; i += lowbit(i)) {
        all[i] += 1;
        st[i] += 1;
    }
    for (int i = R; i <= n; i += lowbit(i)) {
        all[i] -= 1;
    }
}

int query_all(int id) {
    int ans = 0;
    while (id > 0) {
        ans += all[id];
        id -= lowbit(id);
    }
    return ans;
}

int query_st(int id) {
    int ans = 0;
    while (id > 0) {
        ans += st[id];
        id -= lowbit(id);
    }
    return ans;
}

int query(int L, int R) {
    int ans = 0;
    ans += query_all(L - 1);
    ans += query_st(R) - query_st(L - 1);
    return ans;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < q; i++) {
        int op, L, R;
        scanf("%d%d%d", &op, &L, &R);
        if (op == 1) {
            update(L, R);
        }
        if (op == 2) {
            printf("%d\n", query(L, R));
        }
    }
}
