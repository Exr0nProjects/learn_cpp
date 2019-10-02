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
    int f, t, n; // from to next
} edges[MAXSZ * 2];
int head[MAXSZ];
int dist[MAXSZ];

void addEdge(cn a, cn b)
{
    static int cnt = 1;
    edges[cnt].f = a;
    edges[cnt].t = b;
    edges[cnt].n = head[a];
    head[a] = cnt;
    ++cnt;
}

void dfs(cn c, queue<int> q)
{
    q.push(c);
    int m = MAXSZ;
    int mi = 0;
    for (int i = head[c]; i; i = edges[i].n)
    {
        if (dist[edges[i].t] > 0 && m > dist[edges[i].t])
        {
            dist[edges[i].t] = dist[c] + 1;
            m = dist[edges[i].t];
            mi = edges[i].t;
        }
        if (!dist[edges[i].t])
            dfs(edges[i].t, q);
    }
    if (mi > 0)
    {
        for (; !q.empty(); q.pop())
            printf("%3d", q.front());
        printf("\n");
    }
}

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    printf("\n\n%d %d\n\n\n", m, n);
    for (int i = 1; i <= n; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        addEdge(a, b);
    }

    for (int i = 1; i <= m; ++i)
    {
        if (dist[i])
            continue;
        dist[i] = 1;
        dfs(i, queue<int>());
    }

    return 0;
}

/*

4 4
1 2
2 3
3 1
3 4
 */
