#include <iostream>
#include <algorithm>
#include <utility>
//#include <stack>

using namespace std;
const int MX = 1e5+10;

int N, M, ans[MX];
int pre[MX], post[MX], /*low[MX],*/ ncnt=1;
struct Edge { int t, n; } eg[MX<<6]; int hd[MX], ecnt=2;
void addEdge()
{
    //int u = sc();
    //eg[ecnt] = { sc(), hd[u] };
    int u, v; scanf("%d%d", &u, &v);
    eg[ecnt] = { v, hd[u] };
    hd[u] = ecnt++;
}

//stack<int> tstack;
int tstack[MX], sr=0;
int tarj(int c)
{
    //if (pre[c]) return low[c];
    //low[c] = ncnt; // FIX: init low
    int low = ncnt;
    pre[c] = ncnt++;
    tstack[++sr] = c;
    //tstack.push(c);
    for (int e=hd[c]; e && low > 0; e=eg[e].n)
    {
        if (!pre[eg[e].t])      // child of this node (tree path)
            low = min(low, tarj(eg[e].t));
        else if (!ans[eg[e].t]) // existing node in same scc
            low = min(low, pre[eg[e].t]);  // set to pre[n] not low[n] because you can't move any more than that
    }
    if (low == pre[c])   // FIX: equal to pre[c] not ncnt because everything is by pre
    {
        if (c > 1) return -c; // abort, we found another scc (problem specific)
        while (tstack[sr] != c)
            ans[tstack[sr--]] = c;
        ans[c] = c; --sr;
    }
    return low;
}

int main()
{
    // modified for CSES flights rought check (1682). apparently this is the second fastest code for this problem
    int N, M; scanf("%d%d", &N, &M);
    for (int i=1; i<=M; ++i)
        addEdge();
    int g = tarj(1); if (g < 0) { printf("NO\n%d 1\n", -g); return 0; }
    for (int i=2; i<=N; ++i) if (ans[i] != ans[1])
        //{ printf("NO\n%d 1\n", i); return 0; }
    {
        if (pre[i]) printf("NO\n%d 1\n", i);
        else printf("NO\n1 %d", i); // FIX: print in order of impossible
        return 0;
    }
    printf("YES\n");
}
