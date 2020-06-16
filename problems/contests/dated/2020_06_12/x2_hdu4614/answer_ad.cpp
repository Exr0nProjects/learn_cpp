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
const int maxn = 70000;
int n;
int sum[maxn << 1], set_t[maxn << 1];
void set_n(int inn) {
    n = 1;
    while (n < inn) 
        n <<= 1;
}

void push_down(int id, int L, int R) {
    if (set_t[id] != -1) {
        int lc = id << 1, rc = id << 1 | 1, mid = L + R >> 1;
        set_t[lc] = set_t[rc] = set_t[id];
        sum[lc] = (mid - L + 1) * set_t[lc];
        sum[rc] = (R - mid) * set_t[rc];
        set_t[id] = -1;
    }
}

int query_helper(int qL, int qR, int L, int R, int id) {
    if (L > R) return 0;
    if (L > qR || R < qL) return 0;
    if (qL <= L && R <= qR) return sum[id];
    push_down(id, L, R);
    int lc = id << 1, rc = id << 1 | 1, mid = L + R >> 1;
    return query_helper(qL, qR, L, mid, lc) + query_helper(qL, qR, mid + 1, R, rc);
}

int query(int L, int R) {
    return query_helper(L, R, 0, n - 1, 1);
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
        sum[id] = (R - L + 1) * set_t[id];
        return;
    }
    push_down(id, L, R);
    int lc = id << 1, rc = id << 1 | 1, mid = L + R >> 1;
    modify_helper(qL, qR, qv, L, mid, lc);
    modify_helper(qL, qR, qv, mid + 1, R, rc);
    update(id);
}

void modify(int L, int R, int v) {
    modify_helper(L, R, v, 0, n - 1, 1);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(sum, 0, sizeof(sum));
        int inn, q;
        scanf("%d%d", &inn, &q);
        set_n(inn);
        for (int i = 0; i < (n << 1); i++) {
            set_t[i] = -1;
        }
        for (int i = 0; i < q; i++) {
            int op, a, b;
            scanf("%d%d%d", &op, &a, &b);
            if (op == 1) {
                int x = min(inn - a - query(a, inn - 1), b);
                if (x == 0) {
                    printf("Can not put any one.\n");
                    continue;
                }
                int L = a - 1, R = inn - 1;
                while (R - L > 1) {
                    int mid = L + R >> 1;
                    if (mid - a + 1 - query(a, mid) >= x) R = mid;
                    else L = mid;
                }
                int ansR = R;//Right boundary of ans 
                L = a; 
                R = ansR + 1;
                while (R - L > 1) {
                    int mid = L + R >> 1;
                    if (ansR - mid + 1 - query(mid, ansR) >= x) L = mid;
                    else R = mid;
                }
                int ansL = L;
                printf("%d %d\n", ansL, ansR);
                modify(ansL, ansR, 1);
            }
            if (op == 2) {
                printf("%d\n", query(a, b));
                modify(a, b, 0);
            }
        }
        printf("\n");
    }
}

