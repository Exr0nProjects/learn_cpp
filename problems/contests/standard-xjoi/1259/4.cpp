#include <bits/stdc++.h>
#define cn const int
using namespace std;
cn MAXSZ = 110;
struct Edge
{
    int f, t, n; // n can represent next or weight
} edges[MAXSZ*2];
int head[MAXSZ];
int bigb[MAXSZ];
int cnt = 1;

int n;

void addEdge(cn a, cn b)
{
    edges[cnt].f = a;
    edges[cnt].t = b;
    edges[cnt].n = head[a];
    head[a] = cnt;
    ++cnt;
}

int find(cn c) // todo: problem area
{
    int m = 0;
    for (int e=head[c]; e; e=edges[e].n)
    {
        if (m == 0) m = find(edges[e].t);
        else m = min(m, find(edges[e].t));
    }
    if (m < bigb[c])
    {
        bigb[c] = m;
    }
}

int main ()
{
    scanf("%d", &n);
    for (int i=1; i<=n; ++i)
    { // init bigb
        bigb[i] = i;
    }

    priority_queue<Edge*, vector<Edge*>, function<bool(Edge*, Edge*)> > pq([](const Edge* l, const Edge* r){ return l->n > r->n; });
    for (int i=1; i<=n; ++i)
    {
        for (int j=1; j<=n; ++j)
        {
            int w;
            scanf("%d", &w);
            if (w == 0)
            {
                addEdge(i, j);
                find(i);
                find(j);
            }
            else
            {
                Edge* p = new Edge();
                p->f = i;
                p->t = j;
                p->n = w;
                pq.push(p);
            }
        }
    }
    int retc=0, retw=0;
    for (; cnt < n*2-1; pq.pop())
    {
        if (find(pq.top()->f) != find(pq.top()->t))
        {
            addEdge(pq.top()->f, pq.top()->t);
            find(pq.top()->f);
            find(pq.top()->t);
            ++retc;
            retw += pq.top()->n;
        }
    }
    printf("%d\n%d", retc, retw);
}