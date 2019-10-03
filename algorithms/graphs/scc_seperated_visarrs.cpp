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
int m, n;

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
printf("dfs called, c=%d: ", c); auto p = q; printf("\n");
    q.push(c);
    int mn = MAXSZ;
    int mi = 0;
    for (int i = head[c]; i; i = edges[i].n)
    {
        if (dist[edges[i].t] > 0 && mn > dist[edges[i].t])
        {
            mn = dist[edges[i].t];
            mi = edges[i].t;
        }
     printf("    in %d->%d  ", edges[i].f, edges[i].t); for (int j=1; j <= m; ++j) printf("%3d", dist[j]); printf("\n");
        if (!dist[edges[i].t])
        {
          dist[edges[i].t] = dist[c] + 1;
          dfs(edges[i].t, q);
        }
    }
    if (mi > 0)
    {
        for (bool f = false; !q.empty(); q.pop())
        {
          if (q.front() == mn) f = true;
            if (f) printf("%3d", q.front());
        }
        printf("\n");
    }
}

int main()
{
    scanf("%d%d", &m, &n);
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

8 9
1 3
3 2
2 1
1 5
5 7
7 4
7 6
6 4
4 8
4 5
 */
