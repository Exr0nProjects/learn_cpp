/*
 11 Sep 2019
 */

#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 110;
struct Edge
{
    int f, t, n, rem;
} edges[MAXSZ*2];
int head[MAXSZ];

void addEdge (const int a, const int b)
{
    static int c = 1;
    edges[c].f = a;
    edges[c].t = b;
    edges[c].rem = edges[head[a]].rem + 1;
    edges[c].n = head[a];
    head[a] = c;
    ++c;
}

int main()
{
    int p, q;
    scanf("%d%d", &p, &q);
    
    auto comp = [](const int& r, const int& l){return edges[head[r]].rem < edges[head[l]].rem;};
    priority_queue<int, vector<int>, decltype(comp) > pq;
    for (int i=0; i<q; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        addEdge(a, b);
    }
    
    for (int i=0; i<p; ++i) pq.push(i);
    
    for (; !pq.empty(); pq.pop())
    {
        printf("%d ", pq.top());
    }
    
    return 0;
}
