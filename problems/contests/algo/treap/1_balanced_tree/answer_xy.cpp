#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000000;
int n;
int v[maxn], num[maxn], sz[maxn], c[maxn][2], rd[maxn];
int root, cnt;
void setsz(int r) {
    sz[r] = sz[c[r][0]] + sz[c[r][1]] + num[r];
}
void rotate(int &r, int dir) {
    int t = c[r][1 - dir];
    c[r][1 - dir] = c[t][dir];
    setsz(r);
    c[t][dir] = r;
    setsz(t);
    r = t;
}
void ins(int &r, int x) {
    if (!r) {
        v[++cnt] = x;
        num[cnt] = sz[cnt] = 1;
        rd[cnt] = rand();
        r = cnt;
        return;
    }
    if (v[r] == x) {
        sz[r]++;
        num[r]++;
        return;
    }
    int dir = x > v[r];
    ins(c[r][dir], x);
    setsz(r);
    if (rd[c[r][dir]] > rd[r]) rotate(r, 1 - dir);
    setsz(r);
}
void del(int &r, int x) {
    if (!r) return;
    if (x < v[r]) del(c[r][0], x);
    else if (x > v[r]) del(c[r][1], x);
    else {
        if (num[r] > 1) {
            num[r]--;
            sz[r]--;
            return;
        }
        if (!c[r][0] && !c[r][1]) {
            r = 0;
            return;
        }
        else {
            int dir = rd[c[r][0]] < rd[c[r][1]];
            rotate(r, 1 - dir);
            del(c[r][1 - dir], x);
        }
    }
    setsz(r);
}
int find_rank(int r, int x) {
    if (x < v[r]) return find_rank(c[r][0], x);
    if (x > v[r]) return sz[c[r][0]] + num[r] + find_rank(c[r][1], x);
    return sz[c[r][0]] + 1;
}
int find_num(int r, int x) {
    if (x <= sz[c[r][0]]) return find_num(c[r][0], x);
    if (x > sz[c[r][0]] + num[r]) return find_num(c[r][1], x - sz[c[r][0]] - num[r]);
    return v[r];
}
int get_pre(int x) {
    int ans = 2;
    int p = root;
    while (p) {
        if (v[p] == x) {
            if (c[p][0]) {
                p = c[p][0];
                while (c[p][1]) {
                    p = c[p][1];
                }
                ans = p;
            }
            break;
        }
        if (v[p] > v[ans] && v[p] < x) {
            ans = p;
        }
        if (v[p] < x) p = c[p][1];
        else p = c[p][0];
    }
    return v[ans];
}
int get_nxt(int x) {
    int ans = 1;
    int p = root;
    while (p) {
        if (v[p] == x) {
            if (c[p][1]) {
                p = c[p][1];
                while (c[p][0]) {
                    p = c[p][0];
                }
                ans = p;
            }
            break;
        }
        if (v[p] < v[ans] && v[p] > x) ans = p;
        if (v[p] < x) p = c[p][1];
        else p = c[p][0];
    }
    return v[ans];
}
int main() {
    ins(root, INT_MAX);
    ins(root, -INT_MAX);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int op, x;
        scanf("%d%d", &op, &x);
        if (op == 1) {//insert
            ins(root, x);
        }
        if (op == 2) {//delete
            del(root, x);
        }
        if (op == 3) {//find rank of number
            printf("%d\n", find_rank(root, x) - 1);
        }
        if (op == 4) {//find number given rank
            printf("%d\n", find_num(root, x + 1));
        }
        if (op == 5) {
            printf("%d\n", get_pre(x));
        }
        if (op == 6) {
            printf("%d\n", get_nxt(x));
        }
    }
}

