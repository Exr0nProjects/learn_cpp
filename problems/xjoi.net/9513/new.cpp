/*
10 Oct 2019
trying again
*/

#include <bits/stdc++.h>
#define cn const int

using namespace std;

const int MAXSZ = 100010;
struct Edge
{
    int t, n;
} edges[MAXSZ];
int head[MAXSZ], val[MAXSZ], n, q;

void addEdge(cn a, cn b)
{
    static int cnt = 1;
    edges[cnt].t = b;
    edges[cnt].n = head[a];
    head[a] = cnt;
    ++cnt;
}

void trev(cn s, cn v, cn f=0)
{
    for (int p = head[s]; p; p = edges[p].n)
    {
        if (edges[p].t == f) continue;
        val[edges[p].t] += v;
        trev(edges[p].t, v, s);
    }
}

int main ()
{
    scanf("%d%d", &n, &q);
    for (int i=1; i<n; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        addEdge(a, b);
        addEdge(b, a);
    }
    for (int i=0; i<q; ++i)
    {
        int s, v;
        scanf("%d%d", &s, &v);
        trev(s, v);
    }
    for (int i=1; i<=n; ++i)
    {
        printf("%d ", val[n]);
    }
}