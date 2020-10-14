#include <cstdio>

const int MX = 1e5;

int N, sumt[MX<<16], addt[MX<<16], lc[MX<<16], rc[MX<<16], rt[MX], pcnt=1;

void dupe(int &k, int tl, int tr)
{
    sumt[pcnt] = sumt[k];
    addt[pcnt] = addt[k];
    lc[pcnt] = lc[k];
    rc[pcnt] = rc[k];
    k = pcnt++;
}

void apply(int &k, int addv, int tl, int tr)
{
    dupe(k);
    addt[k] = a;
    sumt[k] += a*(tr-tl);
}

void push(int &k, int addv, int tl, int tr)
{
    int mid = tl + tr-tl>>1;
    apply(lc[k], addv, tl, mid);
    apply(rc[k], addv, mid+1, tr);
}

void comb(int &k, int tl, int tr)
{
    sumt[k] = sumt[lc[k]] + sumt[rc[k]];
}

void update(int ql, int qr, int v, int k, int tl=1, int tr=N)
{
    if (qr < tl || tr < ql) return;
    push(k);
    if (tl <= ql && qr <= tr) return apply(k, v, tl, tr);

    int mid = tl + (tr-tl>>1);
    update(ql, qr, v, lc[k], tl, mid);
    update(ql, qr, v, rc[k], mid+1, tr);
    comb(k, tl, tr);
}

int query(int ql, int qr, int v, int k, int tl=1, int tr=N)
{
    if (ql < tl || tr < ql) return 0;
    push(k);
    if (tl <= ql && qr <= tr) return sumt[k] + addt[k]*(tr-tl);
    return query(ql, qr, v, lc[k], tl, mid)
         + query(ql, qr, v, rc[k], mid+1, tr);
}

int main()
{
    scanf("%d", &N);
    for (int i=N; i; --i)
    {

    }
}

