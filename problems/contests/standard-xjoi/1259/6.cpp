// todo: add a traceback array and just print it out
#include <bits/stdc++.h>
#define cn const int
using namespace std;

cn MAXSZ = 1010;
struct Edge
{
    int f, t, w;
    Edge(cn a, cn b, cn c)
    {
        f = a;
        t = b;
        w = c;
    }
    bool operator<(const Edge &o) const { return f < o.f; }
};
vector<Edge> G;
int dist[MAXSZ];
int pre[MAXSZ];
int s, t, m, n; // m = nodes, n = edges

void addEdge(cn a, cn b, cn w)
{
    G.push_back(Edge(a, b, w));
}

int main()
{
    scanf("%d%d%d%d", &s, &t, &m, &n);
    //d*/ printf("%d %d: %d %d\n", s, t, m, n);
    for (int i = 1; i <= n; ++i)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        addEdge(a, b, c); // start from the end and go to the source using backwards edges for lex comp?
    }

    for (int i = 1; i <= m; ++i)
    {
        dist[i] = 100000000;
        pre[i] = 0;
    }

    sort(G.begin(), G.end());

    // bellman ford
    dist[s] = 0;
    //d*/ for (int i=0; i<=m; ++i) printf("%3d", i); printf("\n"); for (int i=0; i<=m; ++i) printf("%3d", dist[i]); printf("\n\n");
    for (int i = 1; i <= m; ++i)
    {
        for (int id = 0; id < G.size(); ++id)
        {
            auto e = G[id];
            //d*/  printf("  checking edge %d-%d: %d", e.f, e.t, e.w);
            if (dist[e.f] + e.w < dist[e.t])
            {
                dist[e.t] = dist[e.f] + e.w;
                pre[e.t] = e.f;
            }
        }
        //d*/  for (int j=0; j<=m; ++j) printf("%3d", j); printf("\n"); for (int j=0; j<=m; ++j) printf("%3d", dist[j]); printf("\n\n");
    }

    for (int id = 0; id < G.size(); ++id)
    {
        auto e = G[id];
        if (dist[e.f] + e.w < dist[e.t])
        {
            printf("You show me the wrong map!");
            return 0;
        }
    }
    string ret;
    for (int n = t; n != s; n = pre[n])
    {
        ret = to_string(n) + " " + ret;
    }
    printf("%d\n%d ", dist[t], s);
    cout << ret;
}

/*
1 4
4 4
1 3 2
1 2 3
2 4 2
3 4 1
 */
