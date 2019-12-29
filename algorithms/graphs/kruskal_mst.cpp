/*
26 Sep 2019
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

const int MAXSZ = 1010;
struct Edge
{
    static int cnt;
    int from, to, weight, next;
} edges[MAXSZ * 2], full[MAXSZ * 2];
int Edge::cnt = 1;
int head[MAXSZ]; // for EdgeList impl
int bigb[MAXSZ]; // for DisjointSet impl

int find(const int c) // DisjointSet `find`
{
    if (bigb[c] == c)
        return c;
    bigb[c] = find(bigb[c]);
    return bigb[c];
}

void addEdge(const int a, const int b, const int w) // add edges to EdgeList from pure data
{
    edges[Edge::cnt].from = a;
    edges[Edge::cnt].to = b;
    edges[Edge::cnt].weight = w;
    edges[Edge::cnt].next = head[a];
    head[a] = Edge::cnt;
    ++Edge::cnt;

    bigb[find(a)] = bigb[find(b)] = min(find(a), find(b)); // needed to init DisjointSet 
}

void addEdge(const Edge &base) // copy insert to EdgeList
{
    edges[Edge::cnt] = base;
    edges[Edge::cnt].next = head[base.from];
    head[base.from] = Edge::cnt;
    ++Edge::cnt;

    bigb[find(base.from)] = bigb[find(base.to)] = min(find(base.from), find(base.to));
}

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    auto cmp = [](const int &l, const int &r) { return full[l].weight > full[r].weight; };
    priority_queue<int, vector<int>, function<bool(int, int)> > pq(cmp); // Used for kruskal
    /* input */
    for (int i = 1; i <= n; ++i)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        full[i].from = a;
        full[i].to = b;
        full[i].weight = w;
        pq.push(i);

        bigb[full[i].from] = full[i].from;
        bigb[full[i].to] = full[i].to;
    }

    int sum = 0;
    for (int vis = 0; !pq.empty(); pq.pop())
    {
        auto cur = full[pq.top()];
        if (find(cur.to) == vis && find(cur.from) == vis)
            continue; // if it leads back to something we already have
        addEdge(cur);
        addEdge(cur.to, cur.from, cur.weight); // other direction
        vis = min(find(cur.to), find(cur.from));
        printf("%d -> %d, %d\n", cur.from, cur.to, cur.weight);
        sum += cur.weight;
        //debug*/ for (int i=1; i<=m; ++i) printf("%3d", i); printf("\n"); for (int i=1; i<=m; ++i) printf("%3d", bigb[i]); printf("\n\n");
    }

    printf("total: %d\n", sum);

    return 0;
}

/* test data
first line: verticies, edges
next #edges lines: from, to, weight
3 3
1 2 3
3 2 1
3 1 2

5 6
1 2 2
1 4 1
2 3 2
3 4 -2
3 5 1
4 5 9
*/
