/*
26 Sep 2019
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1010;
struct Edge
{
    int from, to, weight, next;
    bool operator< (const Edge& o) const
    {
        return 
    }
} edges[MAXSZ*2];
int head[MAXSZ];
int bigb[MAXSZ];

void addEdge (const int a, const int b, const int w)
{
    static int cnt = 1;
    edges[cnt].from = a;
    edges[cnt].to = b;
    edges[cnt].weight = w;
    edges[cnt].next = head[a];
    head[a] = cnt;
    bigb[a] = a;
    ++cnt;
}

int find (const int c)
{
    if (bigb[c] == c) return c;
    bigb[c] = find(bigb[c]);
    return bigb[c];
}

int main ()
{
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i=0; i<n; ++i)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        addEdge(a, b, w);
        addEdge(b, a, w);
    }
    for (int i=0; i<m; ++i)
    {
        if (head[i]) bigb[i] = find(edges[head[i]].to);
    }

    
}