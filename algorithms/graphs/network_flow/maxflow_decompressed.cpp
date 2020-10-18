#define ll long long

const ll inf=1000000000;

struct flowgraph
{
	ll adj[310][310], dep[310], dd[310], ll, rr;
	void addedge(ll x, ll y, ll z)
	{
		if (adj[x][y]<inf) adj[x][y] += z;
	}
	bool bfs()
	{
		memset(dep, 0, sizeof dep);
        rr = 0;
        dd[0]=n+1;  // dd is a queue, start from the end
        dep[n+1]=1;
        // src = 0, sink = n+1
		for (ll = 0; ll<=rr; ll++)
			for(ll i=0; i<=n; i++)
                if (adj[i][dd[ll]] && !dep[i])
                    dep[dd[++rr]=i]=dep[dd[ll]]+1;
		return dep[0];
	}
	ll dfs(ll k, ll mn)
	{
		if (dep[k] == 1) return mn;     // TODO: why dep=1
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
    scanf("%d%d%d%d", &N, &M, &S, &T);
}

