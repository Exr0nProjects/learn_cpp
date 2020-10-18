#define ll long long

const ll inf=1000000000;

struct flowgraph
{
	ll adj[310][310], dep[310], q[310], ll, rr;
	void addedge(ll x, ll y, ll z)
	{
		if (adj[x][y]<inf) adj[x][y] += z;
	}
	bool bfs()
	{
		memset(dep, 0, sizeof dep);
        ll rr = 0;
        q[0]=n+1;  // dd is a queue, start from the end
        dep[n+1]=1;
        // src = 0, sink = n+1
		for (ll ql = 0; ql<=rr; ql++)
			for(ll i=0; i<=n; i++)
                if (adj[i][q[ql]] && !dep[i])
                    dep[q[++rr]=i]=dep[q[ql]]+1;
		return dep[0];
	}
	ll dfs(ll k, ll mn)
	{
		if (dep[k] == 1) return mn;
		ll t = mn;
		for (ll i=1; i<=n+1; i++)
            if (dep[k] == dep[i]+1 && adj[k][i])
            {
                ll o = dfs(i, min(adj[k][i],mn));
                adj[k][i] -= o;
                adj[i][k] += o;
                mn -= o;
                if (!mn) break; // TODO: doesn't update head
            }
		if (t == mn) dep[k] = inf;  // only optimizes on node
		return t-mn;
	}
	ll maxflow()
	{
		ll ret=0;
		for(;bfs();) ret+=dfs(0,inf);
		return ret;
	}
};

int main()
{
    flowgraph g;
    int N, M, S, T;
    scanf("%d%d%d%d", &N, &M, &S, &T);
    while (M--)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g.addedge(u, v, w);
    }
    printf("%lld\n", g.maxflow());
}

