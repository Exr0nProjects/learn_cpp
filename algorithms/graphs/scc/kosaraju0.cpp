// 19 July 2020

#include <cstdio>
#include <cstring>

const int MX = 10111;
struct Edge { int f, t, n; } edges[MX*MX];
int head[MX], ecnt=1, rhead[MX];
void addEdge(int arr[], int a, int b)
{
    edges[ecnt].f = a;
    edges[ecnt].t = b;
    edges[ecnt].n = arr[a];
    arr[a] = ecnt++;
}

int N, M, topo[MX], tcnt=0, comp[MX];   // topological sort of sccs, component ids (basically dsu semantics)

void dfs_topo(int cur)
{
    if (comp[cur]) return;
    comp[cur] = 1;
    for (int e=head[cur]; e; e=edges[e].n)
        dfs_topo(edges[e].t);
    topo[tcnt++] = cur;
}

void dfs_final(int cur, int root)
{
    if (comp[cur]) return;
    comp[cur] = root;
    for (int e=rhead[cur]; e; e=edges[e].n)
        dfs_final(edges[e].t, root);
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=0; i<M; ++i)
    {
        int u, v; scanf("%d%d", &u, &v);
        addEdge(head, u, v);
        addEdge(rhead, v, u);
    }
    for (int i=1; i<=N; ++i)
        dfs_topo(i);
    //for (int i=0; i<N; ++i) printf("%3d", topo[i]); printf("\n");
    memset(comp, 0, sizeof comp); // TODO: VERY IMPORTANT TO CLEAR THIS BETWEEN
    while (tcnt--) dfs_final(topo[tcnt-1], topo[tcnt-1]);
    for (int i=1; i<=N; ++i) printf("%3d: %d\n", i, comp[i]);
}

