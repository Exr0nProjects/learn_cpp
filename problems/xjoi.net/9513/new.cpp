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
int head[MAXSZ], val[MAXSZ] = {}, n, q;

void addEdge(cn a, cn b)
{
    static int cnt = 1;
    edges[cnt].t = b;
    edges[cnt].n = head[a];
    head[a] = cnt;
    ++cnt;
}

void trev(cn s, cn v, cn f = 0)
{
    printf("traversing %d with %d\n", s, v);
    printf("  ");
    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", val[n]);
    }
    printf("\n");
    val[s] += v;
    printf("  ");
    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", val[n]);
    }
    printf("\n");
    return;
    for (int p = head[s]; p; p = edges[p].n)
    {
        printf("  propogating\n");
        if (edges[p].t == f)
            continue;
        trev(edges[p].t, v, s);
    }
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        addEdge(min(a, b), max(a, b));
    }
    for (int i = 1; i <= n; ++i)
    {
        printf("%d: t=%d n=%d\n", i, edges[i].t, edges[i].n);
    }
    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", val[n]);
    }
    printf("\n");
    for (int i = 0; i < q; ++i)
    {
        int s, v;
        scanf("%d%d", &s, &v);
        trev(s, v);
        for (int i = 1; i <= n; ++i)
        {
            printf("%d ", val[n]);
        }
        printf("\n");
    }
    for (int i = 1; i <= n; ++i)
    {
        printf("%d\n", val[n]);
    }
}

/*
5 3
2 1
3 2
3 4
3 5
1 47
2 4
1 63
 
2 1
2 1
2 1
=> 0 1
 */
