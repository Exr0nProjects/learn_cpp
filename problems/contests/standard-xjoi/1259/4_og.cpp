#include <bits/stdc++.h>
#define cn const int
using namespace std;
cn MAXSZ = 1010;
struct Edge
{
    int f, t, n; // n can represent next or weight
} edges[MAXSZ * MAXSZ];
int head[MAXSZ];
int bigb[MAXSZ];
int cnt = 1;

int n;

void addEdge(cn a, cn b)
{
    //    printf("  adding %d, %d\n", a, b);
    edges[cnt].f = a;
    edges[cnt].t = b;
    edges[cnt].n = head[a];
    head[a] = cnt;
    ++cnt;
}

int find(cn c, cn p = 0) // todo: problem area
{
    //    int m = 0;
    //    for (int e=head[c]; e; e=edges[e].n)
    //    {
    //        if (m == 0) m = find(edges[e].t);
    //        else m = min(m, find(edges[e].t));
    //    }
    //    if (m < bigb[c])
    //    {
    //        bigb[c] = m;
    //    }
    if (bigb[c] != c && bigb[c] != p)
    {
        bigb[c] = find(bigb[c], c);
    }
    return bigb[c];
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    { // init bigb
        bigb[i] = i;
    }

    priority_queue<Edge *, vector<Edge *>, function<bool(Edge *, Edge *)>> pq([](const Edge *l, const Edge *r) { return l->n > r->n; });
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {

            int w;
            scanf("%d", &w);
            if (i == j)
                continue;
            if (w == 0)
            {
                addEdge(i, j);
                bigb[find(max(i, j))] = min(i, j);
            }
            else
            {
                Edge *p = new Edge();
                p->f = i;
                p->t = j;
                p->n = w;
                pq.push(p);
            }
        }
        //d*/ printf("\n");
    }
    //    for (int i = 1; i <= n; ++i)
    //        printf("%3d", i);
    //    printf("\n");for (int i = 1; i <= n; ++i)
    //        printf("%3d", find(i));
    //d*/    printf("\n\n");
    int retc = 0, retw = 0;
    //d*/ printf("%d %d\n", cnt, n);
    for (; cnt < n * 2 - 2; pq.pop())
    {
        if (pq.top()->n != 0 && find(pq.top()->f) != find(pq.top()->t))
        {
            //d*/ printf("adding %d-%d: %d\n", pq.top()->f, pq.top()->t, pq.top()->n);
            addEdge(pq.top()->f, pq.top()->t);
            addEdge(pq.top()->t, pq.top()->f);
            bigb[find(max(pq.top()->f, pq.top()->t))] = min(pq.top()->f, pq.top()->t);
            ++retc;
            retw += pq.top()->n;
        }
    }
    printf("%d\n%d", retc, retw);
}

/*
5
0 15 27 6 0
15 0 33 19 11
27 33 0 0 17
6 19 0 0 9
0 11 17 9 0

3
0 10 20
10 0 0
20 0 0
*/
