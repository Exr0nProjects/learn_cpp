#include <iostream>

const int MX = 1e5+10;
int N, M, ans[MX];
int pre[MX], post[MX], low[MX], ncnt=1;
struct Edge { int t, n; } eg[MX<<6]; int hd[MX], ecnt=2;
void addEdge()
{
    int u = sc();
    eg[ecnt] = { sc(), hd[u] };
    hd[u] = ecnt++;
}

stack<int> tstack;
int tarj(int c)
{
    if (pre[c]) return;
    pre[c] = ncnt++;
    tstack.push(c);
    for (int e=hd[c]; e; e=eg[e].n)
    {
        //tarj(eg[e].n);
        if (!pre[eg[e].t])      // child of this node (tree path)
            low[c] = min(low[c], tarj(eg[e].t));
        else if (!ans[eg[e].t]) // existing node in same scc
            low[c] = min(low[c], low[eg[e].t]);
    }
    //post[c] = ncnt;
    if (low[c] == ncnt)
    {
        while (tstack.top() != c)
            ans[tstack.top()] = c, tstack.pop();
        ans[c] = c; tstack.pop();
    }
}

