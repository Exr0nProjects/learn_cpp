/*
2 Oct 2019
Strongly Connected Components
*/

#include <bits/stdc++.h>
#define cn const int
using namespace std;

cn MAXSZ = 100;
struct Edge
{
    int f, t, w, n; // from to next weight
} edges[MAXSZ*2];
int head[MAXSZ];
int dist[MAXSZ];

void addEdge(cn a, cn b, cn w)
{
    static int cnt = 1;
    edges[cnt].f = a;
    edges[cnt].t = b;
    edges[cnt].w = w;
    edges[cnt].n = head[a];
    head[a] = cnt;
    ++cnt; 
}

void dfs (cn c)
{
    m = MAXSZ;
    mi = 0;
    for (int i=head[c]; i; i=edges[i].n)
    {
        if (dist[edges[i].t] > 0 && m > dist[edges[i].t])
        {
            m = dist[edges[i].t];
            mi = edges[i].t;
        }
        dfs(edges[i].t);
    }
    if (mi > 0) printf()
}

int main ()
{
    int m,n;
    scanf("%d%d", &m, &n);
    for (int i=1; i<=n; ++i)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        addEdge(a, b, w);
    }
    for (int i=1; i<=m; ++i)
    {
        if (i) continue;
        dist[i] = 1;
        dfs(i);
    }
}