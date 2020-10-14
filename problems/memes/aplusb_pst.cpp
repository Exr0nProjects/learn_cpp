#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int MX = 1e5;

int N, sumt[MX<<6], addt[MX<<6], lc[MX<<6], rc[MX<<6], rt[MX], rcnt=1, pcnt=1;

void dump(int k)
{
    int d = N<<1-1;
    queue<int> q;
    q.push(rt[k]);
    for (int i=1; i<N<<1; ++i)
    {
        if (__builtin_popcount(i) == 1) { d >>= 1; printf("\n"); }
        k = q.front(); q.pop();
        q.push(lc[k]); q.push(rc[k]);
        printf("%3d: %2d +%-2d", k, sumt[k], addt[k]);
        for (int i=0; i<d; ++i) printf("         ");
    }
    printf("\n");
}

void dupe(int &k)
{
    sumt[pcnt] = sumt[k];
    addt[pcnt] = addt[k];
    lc[pcnt] = lc[k];
    rc[pcnt] = rc[k];
    printf("k %d -> %d\n", k, pcnt);
    k = pcnt++;
}

void apply(int &k, int addv, int tl, int tr)
{
    dupe(k);
    addt[k] += addv;
    sumt[k] += addv*(tr-tl);
}

void push(int &k, int tl, int tr)
{
    //dupe(k);
    int mid = tl + (tr-tl>>1);
    apply(lc[k], addt[lc[k]], tl, mid);
    apply(rc[k], addt[rc[k]], mid+1, tr);
    addt[k] = 0;
}

void comb(int &k, int tl, int tr)
{
    sumt[k] = sumt[lc[k]] + sumt[rc[k]];
}

int update(int ql, int qr, int v, int &k, int tl=1, int tr=N)
{
    printf("    updat %d..%d @ %d (%d..%d) for %d\n", ql, qr, k, tl, tr, v);
    if (qr < tl || tr < ql) return 0;
    //if (ql <= tl && tr <= qr) return apply(k, v, tl, tr);
    if (ql <= tl && tr <= qr) return addt[k] = v;

    push(k, tl, tr);
    int mid = tl + (tr-tl>>1);
    update(ql, qr, v, lc[k], tl, mid);
    update(ql, qr, v, rc[k], mid+1, tr);
    comb(k, tl, tr);
}

int query(int ql, int qr, int &k, int tl=1, int tr=N)
{
    printf("    query %d..%d @ %d (%d..%d)\n", ql, qr, k, tl, tr);
    if (ql < tl || tr < ql) return 0;
    //if (ql <= tl && tr <= qr) return sumt[k] + addt[k]*(tr-tl);
    if (ql <= tl && tr <= qr) return sumt[k];
    push(k, tl, tr);
    int mid = tl + (tr-tl>>1);
    return query(ql, qr, lc[k], tl, mid)
         + query(ql, qr, rc[k], mid+1, tr);
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    N = max(a, b);
    //rt[rcnt++] = pcnt++;
    while (a--)
    {
        printf("now %d\n", a);
        rt[rcnt] = rt[rcnt-1];
        dupe(rt[rcnt]);
        dump(rt[rcnt]);
        update(a+1, a+1, 1, rt[rcnt++]);
        dump(rt[rcnt-1]);
    }
    while (b--)
    {
        printf("now %d\n", b);
        rt[rcnt] = rt[rcnt-1];
        dupe(rt[rcnt]);
        dump(rt[rcnt]);
        update(b+1, b+1, 1, rt[rcnt++]);
        dump(rt[rcnt-1]);
    }
    printf("%d\n", query(1, N, rt[rcnt-1]));
}

