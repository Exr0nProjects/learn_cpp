#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 100005;
int n, tag, l[N], r[N], c[N], stat[N];
int nume, h[N];
struct Edge {
    int v, nxt;
} e[N << 1];
void add_edge(int u, int v) {
    e[++nume] = (Edge) {v, h[u]};
    h[u] = nume;
    e[++nume] = (Edge) {u, h[v]};
    h[v] = nume;
}
void dfs(int t, int fa) {
    l[t] = ++tag;
    for (int i = h[t]; i; i = e[i].nxt) {
        if (e[i].v != fa) {
            dfs(e[i].v, t);
        }
    }
    r[t] = tag;
}
void modify(int p, int v) {
    for (; p <= n; p += p & -p) {
        c[p] += v;
    }
}
int query(int p) {
    int ret = 0;
    for (; p; p -= p & -p) {
        ret += c[p];
    }
    return ret;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) {
        modify(l[i], 1);
        stat[l[i]] = 1;
    }
    int q;
    for (scanf("%d", &q); q--;) {
        char c;
        int t;
        scanf(" %c%d", &c, &t);
        if (c == 'Q') {
            printf("%d\n", query(r[t]) - query(l[t] - 1));
        } else {
            modify(l[t], stat[l[t]] ? -1 : 1);
            stat[l[t]] = !stat[l[t]];
        }
    }
    return 0;
}

