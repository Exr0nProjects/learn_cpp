// todo: add a traceback array and just print it out
#include <bits/stdc++.h>
#define cn const int;
using namespace std;

cn MAXSZ = 1010;
struct Edge
{
    int f, t, w, n;
} edges[MAXSZ*MAXSZ];
int s, t, m, n, cnt=1; // m = nodes, n = edges

void addEdge(cn a, cn b, cn w)
{
    edges[cnt].f = a;
    edges[cnt].t = b;
    edges[cnt].w = w;
    edges[cnt].n = head[a];
    head[a] = cnt;
    ++cnt;
}

int main ()
{
    scanf("%d%d%d%d", &s, &t, &m, &n);
    printf("%d %d: %d %d\n", s, t, m, n);
    for (int i=1; i<=n; ++i)
    {
        int a, b, c;
        scanf("%d%d%d", &a ,&b, &c);
        addEdge(a, b, c);
        addEdge(b, a, c);
    }
}