#include <utility>
#include <string>

using namespace std;
#define f first
#define s second
typedef pair <int, int> pii;
const int maxn = 500010;
const long long ninf = -10000000000000;

void setIO(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

struct node {
    long long sum;
    pair <long long, pii> lali, rali, nore;//left align, right align, no restriction
    //first number is the maximum value, then it is the L and R
}st[4 * maxn];//segment tree

int n, m;
void init(int _n) {
    n = 1;
    while (n < _n)
        n <<= 1;
}

pair <long long, pii> cmp(pair <long long, pii> x, pair <long long, pii> y) {
    if (x.f > y.f) return x;
    if (x.f < y.f) return y;
    if (x.s.f < y.s.f) return x;
    if (x.s.f > y.s.f) return y;
    if (x.s.s < y.s.s) return x;
    return y;
}

void setn(int id, int L, int R) {
    if (id >= n - 1) return;
    int lc = id * 2 + 1, rc = id * 2 + 2, d = (R - L) / 2;
    setn(lc, L, L + d);
    setn(rc, L + d + 1, R);
    st[id].sum = st[lc].sum + st[rc].sum;
    if (st[lc].lali.f >= st[lc].sum + st[rc].lali.f)
        st[id].lali = {st[lc].lali.f, {L, st[lc].lali.s.s}};
    else
        st[id].lali = {st[lc].sum + st[rc].lali.f, {L, st[rc].lali.s.s}};

    if (st[lc].rali.f + st[rc].sum >= st[rc].rali.f)
        st[id].rali = {st[lc].rali.f + st[rc].sum, {st[lc].rali.s.f, R}};
    else
        st[id].rali = {st[rc].rali.f, {st[rc].rali.s.f, R}};
    pair <long long, pii> nr = st[rc].nore, nl = st[lc].nore, ib = {st[lc].rali.f + st[rc].lali.f, {st[lc].rali.s.f, st[rc].lali.s.s}};
    pair <long long, pii> mx = cmp(nr, nl);
    mx = cmp(mx, ib);
    st[id].nore = mx;
}

pair <long long, pii> query_helper(int qL, int qR, int id, int L, int R, int tp) {
    //tp is type, 0 for no restriction, 1 for left align, 2 for right align
    if (L > R) return {ninf, {0, 0}};
    if (L > qR || R < qL) return {ninf, {-1, -2}};
    if (qL <= L && R <= qR) {
        if (tp == 0) return st[id].nore;
        if (tp == 1) return st[id].lali;
        return st[id].rali;
    }
    int lc = 2 * id + 1, rc = 2 * id + 2, d = (R - L) / 2;
    if (tp == 1) {
        pair <long long, pii> lq = query_helper(qL, qR, lc, L, L + d, 1), rq = query_helper(qL, qR, rc, L + d + 1, R, 1);
        rq.f += st[lc].sum;
        rq.s.f = L;
        return cmp(lq, rq);
    }
    if (tp == 2) {
        pair <long long, pii> lq = query_helper(qL, qR, lc, L, L + d, 2), rq = query_helper(qL, qR, rc, L + d + 1, R, 2);
        lq.f += st[rc].sum;
        lq.s.s = R;
        return cmp(lq, rq);
    }
    pair <long long, pii> lq = query_helper(qL, qR, lc, L, L + d, 0), rq = query_helper(qL, qR, rc, L + d + 1, R, 0);
    pair <long long, pii> ls = query_helper(qL, qR, lc, L, L + d, 2), rs = query_helper(qL, qR, rc, L + d + 1, R, 1);
    pair <long long, pii> ib = {ls.f + rs.f, {ls.s.f, rs.s.s}};
    pair <long long, pii> mx = cmp(lq, rq);
    mx = cmp(mx, ib);
    return mx;
}

pair <long long, pii> query(int L, int R) {
    return query_helper(L, R, 0, 0, n - 1, 0);
}

int main() {
    //setIO("1400");
    int inn, cs = 0;
    while (scanf("%d%d", &inn, &m) == 2) {
        init(inn);
        for (int i = 0; i < 2 * n; i++) {
            st[i].sum = st[i].lali.f = st[i].rali.f = st[i].nore.f = ninf;
        }
        for (int i = 0; i < inn; i++) {
            int x;
            scanf("%d", &x);
            int k = n - 1 + i;
            st[k].sum = st[k].lali.f = st[k].rali.f = st[k].nore.f = x;
            st[k].lali.s = st[k].rali.s = st[k].nore.s = {i, i};
        }
        setn(0, 0, n - 1);
        printf("Case %d:\n", ++cs);
        for (int i = 0; i < m; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            pair <long long, pii> ans = query(x - 1, y - 1);
            printf("%d %d\n", ans.s.f + 1, ans.s.s + 1);
        }
    }
}
