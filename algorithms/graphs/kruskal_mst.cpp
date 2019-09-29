/*
26 Sep 2019
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1010;
struct Edge
{
    static int cnt;
    int from, to, weight, next;
    bool operator< (const Edge& o) const
    {
        return 
    }
} edges[MAXSZ*2], full[MAXSZ*2];
int Edge::cnt = 1;
int head[MAXSZ];
int bigb[MAXSZ];

void addEdge (const int a, const int b, const int w)
{
    edges[Edge::cnt].from = a;
    edges[Edge::cnt].to = b;
    edges[Edge::cnt].weight = w;
    edges[Edge::cnt].next = head[a];
    head[a] = Edge::cnt;
    ++Edge::cnt;
}

void addEdge (const Edge& base)
{
    edges[Edge::cnt] = base;
    edges[Edge::cnt].next = head[base.from];
    head[base.from] = Edge::cnt;
    ++Edge::cnt;
}

int find (const int c)
{
    if (bigb[c] == 0) bigb[c] = bigb[edges[head[c]].to];
    if (bigb[c] == c) return c;
    bigb[c] = find(bigb[c]);
    return bigb[c];
}

int main ()
{
    int m, n;
    scanf("%d%d", &m, &n);
    auto cmp = [](const int& l, const int& r) { return full[l].weight < full[r].weight; };
    priority_queue<int, vector<int>, function<bool(int, int)> > pq(cmp);
    for (int i=1; i<=n; ++i)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        full[i].from = a;
        full[i].to = b;
        full[i].weight = w;
        pq.push(i);
    }
    printf("%d\n", full[pq.top()].weight); // debug, todo: remove
    for (int vis = 0; ! pq.empty(); pq.pop())
    {
        auto cur = full[pq.top()];
        if (bigb[cur.to] == vis) continue; // if it leads back to something we already have
        addEdge(cur);
        addEdge(cur.to, cur.from, cur.weight); // other direction
        vis = find(cur.to);
        printf("%d -> %d, %d\n", cur.from, cur.to, vis);
    }

    return 0;
}