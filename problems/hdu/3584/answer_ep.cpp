#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 105;
int n, d[N][N][N];
void modify(int p, int q, int r) {
    for (; p <= n; p += p & -p) {
        for (int tq = q; tq <= n; tq += tq & -tq) {
            for (int tr = r; tr <= n; tr += tr & -tr) {
                d[p][tq][tr] = !d[p][tq][tr];
            }
        }
    }
}
int query(int p, int q, int r) {
    int ret = 0;
    for (; p; p -= p & -p) {
        for (int tq = q; tq; tq -= tq & -tq) {
            for (int tr = r; tr; tr -= tr & -tr) {
                if (d[p][tq][tr]) {
                    ret = !ret;
                }
            }
        }
    }
    return ret;
}
int main() {
    for (; ~scanf("%d", &n);) {
        memset(d, 0, sizeof d);
        int q;
        for (scanf("%d", &q); q--;) {
            int t;
            scanf("%d", &t);
            if (t) {
                int x1, y1, z1, x2, y2, z2;
                scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
                modify(x1, y1, z1);
                modify(x1, y1, z2 + 1);
                modify(x1, y2 + 1, z1);
                modify(x2 + 1, y1, z1);
                modify(x1, y2 + 1, z2 + 1);
                modify(x2 + 1, y1, z2 + 1);
                modify(x2 + 1, y2 + 1, z1);
                modify(x2 + 1, y2 + 1, z2 + 1);
            } else {
                int x, y, z;
                scanf("%d%d%d", &x, &y, &z);
                printf("%d\n", query(x, y, z));
            }
        }
    }
    return 0;
}

