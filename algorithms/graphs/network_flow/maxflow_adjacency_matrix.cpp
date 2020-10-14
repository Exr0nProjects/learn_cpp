#define llint long long

const llint inf=1000000000;
 
struct flowgraph
{
	llint a[310][310],h[310],dd[310],ll,rr;
	void addedge(llint x,llint y,llint z)
	{
		if (a[x][y]<inf) a[x][y]+=z;
	}
	bool bfs()
	{
		memset(h,0,sizeof h);
		for(h[dd[ll=rr=0]=n+1]=1;ll<=rr;ll++)
			for(llint i=0;i<=n;i++) if (a[i][dd[ll]]&&!h[i])
				h[dd[++rr]=i]=h[dd[ll]]+1;
		return h[0];
	}
	llint dfs(llint k,llint now)
	{
		if (h[k]==1) return now;
		llint t=now;
		for(llint i=1;i<=n+1;i++) if (h[k]==h[i]+1&&a[k][i])
		{
			llint o=dfs(i,min(a[k][i],now));
			a[k][i]-=o; now-=o; a[i][k]+=o;
			if (!now) break;
		}
		if (t==now) h[k]=inf;
		return t-now;
	}
	llint maxflow()
	{
		llint ret=0;
		for(;bfs();) ret+=dfs(0,inf);
		return ret;
	}
};